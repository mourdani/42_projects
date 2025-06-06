import { NestFactory } from '@nestjs/core';
import * as cors from 'cors';
import { AppModule } from './app.module';
import { SwaggerModule, DocumentBuilder } from '@nestjs/swagger';
import { ValidationPipe } from '@nestjs/common';
import './socket-io.gateway';
import { createRoom, movePaddle, sleep } from './game-socket';
import { Game } from './game-socket';
import { createRoomFr } from './game-socket';
import { Player } from './game-socket';
import { v4 as uuidV4 } from 'uuid';

const socketIO = require('socket.io');

export const connectedUsers = new Map<string, string>([]);
export const rooms = new Map<string, Game>();

async function bootstrap() {
	const app = await NestFactory.create(AppModule);
	app.useGlobalPipes(new ValidationPipe());

	const config = new DocumentBuilder()
		.setTitle('Median')
		.setDescription('The Median API description')
		.setVersion('0.1')
		.build();

	const document = SwaggerModule.createDocument(app, config);
	SwaggerModule.setup('api', app, document);

	app.use(cors({
		origin: '*'
	}));

	const httpServer = await app.listen(3000);

	const io = socketIO(httpServer, { cors: { origin: '*' } });

	io.on('connection', (socket) => {
		console.log('Client connected');


		socket.on('log-in', (id: string) => {
			connectedUsers.set(id, socket.id);
			console.log(connectedUsers);
			io.emit('log-in', id);
		})

		socket.on('log-out', (id: string) => {
			connectedUsers.delete(id);
			console.log(connectedUsers);
			io.emit('log-out', id);
		})
		
		function leavePong() {
			// Remove the disconnected player from all rooms they were in
			rooms.forEach((value, key) => {
				let index = value.players.findIndex(function (item) {
					return item.socketId === socket.id;
				});

				if (index !== -1) {
					value.gameOver = true;
					value.players.splice(index, 1); // Remove the socket ID from the room's player list
					//if player left, tell them the game is over
					if (value.players.length === 1) {
						io.to(value.players[0].socketId).emit('opponent-left');
					}
					//delete room
					rooms.delete(key);
				}
			});
		}

		socket.on('disconnect', () => {
			console.log('Client disconnected');
			for (let value of connectedUsers) {
				if (value[1] === socket.id) {
					connectedUsers.delete(value[0]);
				}
			}
			leavePong();
		});

		socket.on('leaving-pong', (str: string) => {
			leavePong();
		})

		socket.on('update-room', (data) => {
			// Handle 'new-room' event here
			console.log('New room:', data);

			// Emit the 'new-room' event to all connected clients
			io.emit('update-room', data);
		});

		socket.on('message', (data) => {
			// Handle message event here
			console.log('New message:', data);

			// Emit the 'new-message' event to all connected clients except the one who sent the message
			io.emit('new-message', data);
		});

		socket.on("user-status", (id: string, callback) => {
			let res = Array.from(rooms.values()).filter((room: Game) => {
				return ((room.players.length > 0 && room.players[0].userId === id) ||
					(room.players.length > 1 && room.players[1].userId === id))
			});
			if (res.length !== 0) {
				callback(2);
			} else if (connectedUsers.get(id) !== undefined) {
				callback(1)
			} else {
				callback(0);
			}
		})

		socket.on("invite", (invitingId: string, invitedId: string, isExpert: boolean, callback) => {
			let roomId = uuidV4();
			createRoomFr(roomId, [], isExpert, true);

			console.log(isExpert);
			io.to(connectedUsers.get(invitedId)).emit("invited", invitingId, roomId);
			callback();
		})

		socket.on("uninvite", (invitingId: string, invitedId: string, callback) => {
			io.to(connectedUsers.get(invitedId)).emit("uninvited", invitingId, () => { });
		})

		socket.on("accept-invite", async (invitingId: string, roomId: string) => {
			io.to(connectedUsers.get(invitingId)).emit("invite-accepted", roomId, () => { });
			socket.emit("invite-accepted", roomId, () => { });
		})

		socket.on("refuse-invite", (id: string, roomId: string, callback) => {
			console.log("invite refused");
			rooms.delete(roomId);
			io.to(connectedUsers.get(id)).emit("invite-refused", () => { });
		})

		createRoom(socket, io);

		movePaddle(socket, io);
	});
}

bootstrap();