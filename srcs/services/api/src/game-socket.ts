import { Socket } from "socket.io";
import { v4 as uuidV4 } from 'uuid';
import { rooms } from "./main";
import { GameService } from "./game/game.service";
import { PrismaService } from "./prisma/prisma.service";
import { connectedUsers } from "./main";

export interface Player {
	socketId: string,
	userId: string,
	score: number,
	paddle: {
		x: number,
		y: number
	}
}

export interface Game {
	isExpert: boolean,
	isPrivate: boolean,
	players: Array<Player>,
	winScore: number,
	ball: {
		x: number,
		y: number,
		xspeed: number,
		yspeed: number,
		radius: number,
	},
	paddle: {
		height: number,
		width: number
	}
	ratio: number,
	gameOver: boolean,
	bonus: {
		x: number,
		y: number,
		xspeed: number,
		yspeed: number,
		radius: number,
		type: number,
		text: string,
		color: string
	}
}

export const sleep = async (milliseconds) => {
	await new Promise(resolve => {
		return setTimeout(resolve, milliseconds)
	});
};

async function closeRoom(socket: Socket, io: any, roomId: string) {
	const clientsSockets = await io.in(roomId).fetchSockets();
	clientsSockets.forEach((s) => {
		s.leave(roomId);
	});
	rooms.delete(roomId);

}

function checkPaddleCollision(room: Game, player: number) {
	if ((player === 0 && room.ball.x - room.ball.radius <= room.players[player].paddle.x + room.paddle.width)
		|| (player === 1 && room.ball.x + room.ball.radius >= room.players[player].paddle.x)) {
		if (room.ball.y >= room.players[player].paddle.y && room.ball.y <= room.players[player].paddle.y + room.paddle.height) {
			room.ball.xspeed *= -1;
			const middleY = room.players[player].paddle.y + room.paddle.height / 2;
			const diffY = middleY - room.ball.y;
			room.ball.yspeed = room.ball.xspeed * 2 / room.paddle.height * diffY * room.ratio;
			room.ball.x = room.players[player].paddle.x;
			if (player === 0) {
				room.ball.yspeed *= -1;
				room.ball.x += room.paddle.width + room.ball.radius;
			} else {
				room.ball.x -= room.ball.radius;
			}
		}
	}
}

function increaseScore(room: Game, io: any, roomId: string, winner: number, value: number, socket: Socket) {

	let gameOver: boolean = false;

	room.players[winner].score += value;

	io.to(roomId).emit('update-scores', {
		players: room.players
	});

	//add match to db
	if (room.players[winner].score === room.winScore) {
		const gameService = new GameService(new PrismaService());
		gameService.add_match({
			winner_id: +room.players[winner].userId,
			loser_id: +room.players[1 - winner].userId,
			winner_score: room.players[winner].score,
			loser_score: room.players[1 - winner].score,
		}).then(() => {
			gameService.checkAchievements(+room.players[0].userId, room.players[0].socketId, io);
			gameService.checkAchievements(+room.players[1].userId, room.players[1].socketId, io);
		})
		room.gameOver = true;
		gameOver = true;
		io.to(roomId).emit('game-over', { gameOver });
		closeRoom(socket, io, roomId);
	}
}

function checkScore(room: Game, io: any, roomId: string, socket: Socket) {
	// Check if the ball is still in the canvas
	if (room.ball.x - room.ball.radius <= 0 || room.ball.x + room.ball.radius >= 1) {
		let winner = room.ball.x - room.ball.radius <= 0 ? 1 : 0; //get the index of winner
		increaseScore(room, io, roomId, winner, 1, socket);

		// If not, the ball is reset in the middle of the screen
		room.ball.x = 0.5;
		room.ball.y = 0.5;

		// Reverse the horizontal direction of the ball
		room.ball.xspeed *= (room.players[0].score + room.players[1].score) % 2 === 0 ? -1 : 1; //check if total score is even or uneven to alternate who starts
		room.ball.yspeed = 0;
	}
}

function updateBall(room: Game, io: any, roomId: string, socket: Socket) {
	//check horizontal wall collision
	if (room.ball.y - room.ball.radius / 2 <= 0 || room.ball.y + room.ball.radius / 2 >= 1) {
		room.ball.yspeed *= -1;
	}

	checkScore(room, io, roomId, socket);
	checkPaddleCollision(room, 0);
	checkPaddleCollision(room, 1);

	room.ball.x += room.ball.xspeed;
	room.ball.y += room.ball.yspeed;
}

function updateBonus(room: Game, io: any, roomId: string, socket: Socket) {
	if (!room.bonus) {
		if (Math.random() < 0.995)
			return;
		else {
			const type = Math.random() < 0.5 ? 1 : 2;
			room.bonus = {
				x: 0.5,
				y: 0.5,
				xspeed: Math.random() < 0.5 ? 0.01 : -0.01,
				yspeed: 0.01 / room.ratio,
				radius: 0.02,
				type: type,
				text: type === 1 ? "+1" : "-1",
				color: type === 1 ? "#043b12" : "#520404"
			}
			sleep(5000).then(() => {
				room.bonus = null;
			})
		}
	}

	room.bonus.x += room.bonus.xspeed;
	room.bonus.y += room.bonus.yspeed;

	if (room.bonus.y - room.bonus.radius / 2 <= 0 || room.bonus.y + room.bonus.radius / 2 >= 1) {
		room.bonus.yspeed *= -1;
	}
	if (room.bonus.x - room.bonus.radius / 2 <= 0 || room.bonus.x + room.bonus.radius / 2 >= 1) {
		room.bonus.xspeed *= -1;
	}

	if (room.bonus.x - room.bonus.radius <= room.players[0].paddle.x + room.paddle.width) {
		if (room.bonus.y >= room.players[0].paddle.y && room.bonus.y <= room.players[0].paddle.y + room.paddle.height) {
			increaseScore(room, io, roomId, 0, room.bonus.type === 1 ? 1 : -1, socket);
			room.bonus = null;
		}
	} else if (room.bonus.x + room.bonus.radius >= room.players[1].paddle.x) {
		if (room.bonus.y >= room.players[1].paddle.y && room.bonus.y <= room.players[1].paddle.y + room.paddle.height) {
			increaseScore(room, io, roomId, 1, room.bonus.type === 1 ? 1 : -1, socket);
			room.bonus = null;
		}
	}
}

async function moveBall(room: Game, io: any, roomId: string, socket: Socket) {
	try {
		while (!room.gameOver) {
			updateBall(room, io, roomId, socket);
			if (room.isExpert)
				updateBonus(room, io, roomId, socket);
			await sleep(20);
		}
	} catch (error) { console.log(error) }
}

export function movePaddle(socket: Socket, io: any) {
	socket.on('move-paddle', async (roomId: string, userId: string, paddle: { x: number, y: number }, callback) => {
		let i: number;
		const room = rooms.get(roomId);

		if (room === undefined || room.players.length != 2) {
			return;
		}
		if (room.players[0].userId === userId)
			i = 0;
		else
			i = 1;
		room.players[i].paddle.x = paddle.x;
		room.players[i].paddle.y = paddle.y;
		callback(room);
	})
}

export async function createRoomFr(roomId: string, players: Player[], isExpert: boolean, isPrivate: boolean) {

	rooms.set(roomId, {
		isExpert,
		isPrivate,
		players,
		winScore: 11,
		ball: {
			x: 0.5,
			y: 0.5,
			xspeed: 0.015,
			yspeed: 0.015 / 1.75,
			radius: 0.015,
		},
		paddle: {
			height: 0.15,
			width: 0.01
		},
		ratio: 1.75,
		gameOver: false,
		bonus: null
	});
}

//try to join room or create one if none is open
export async function createRoom(socket: Socket, io: any) {
	socket.on('create-room', async (isExpert: boolean, userId: string, joiningRoomId: string | undefined, callback) => { // callback here refers to the callback function from the client passed as data
		console.log("HERE");
		let roomId = "";
		if (joiningRoomId === undefined) {
			joiningRoomId = null
		}

		io.emit("in-game", userId);
		rooms.forEach((value: Game, key: string) => {
			if (roomId.length === 0) {
				//there is enough room left
				if (!(value.players.length === 2 || (value.players.length === 1 && value.players[0].userId === userId))) {
					//if joining specific room
					if (joiningRoomId && value.isPrivate && joiningRoomId === key) {
						roomId = key;
					}
					//else check if difficulty level is correct
					else if (!joiningRoomId && !(value.isPrivate) && isExpert === value.isExpert) {
						roomId = key;
					}
				}
			}
		});

		//if we found a room with someone else, there's a room with two people, so we start a countdown to the start of game
		if (roomId && roomId.length !== 0) {
			let room = rooms.get(roomId);
			socket.join(roomId);
			room.players.push({ userId: userId, socketId: socket.id, score: 0, paddle: { x: 0, y: 0 } })
			console.log("joining room");

			callback(roomId);

			if (room.players.length < 2)
				return;
			io.to(room.players[0].socketId).emit('player-joined', room);
			io.to(room.players[1].socketId).emit('player-joined', room);

			io.to(roomId).emit('countdown', 3);
			await sleep(1000);
			io.to(roomId).emit('countdown', 2);
			await sleep(1000);
			io.to(roomId).emit('countdown', 1);
			await sleep(1000);
			io.to(roomId).emit('game-start');
			moveBall(rooms.get(roomId), io, roomId, socket);
			return;
		}

		roomId = (joiningRoomId !== undefined && joiningRoomId !== null ? joiningRoomId : uuidV4());
		let players: Player[] = [{ userId: userId, socketId: socket.id, score: 0, paddle: { x: 0, y: 0 } }];
		socket.join(roomId);
		createRoomFr(roomId, players, isExpert, false);

		console.log("creating room");
		console.log(rooms);
		callback(roomId);
	});
}
