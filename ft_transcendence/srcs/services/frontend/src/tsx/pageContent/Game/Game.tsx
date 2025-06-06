import React, { useEffect, useRef } from 'react';
import './../../../css/pageContent/Game/Game.css';
import { socket } from '../../App';

export interface Player {
	socketId: string,
	userId: string,
	score: number,
	paddle: {
		x: number,
		y: number
	}
}

export interface Room {
	isExpert: boolean,
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
		color: string,
	}
}

interface Props {
	score1: React.MutableRefObject<number>;
	score2: React.MutableRefObject<number>;
	userId1: React.MutableRefObject<string>;
	userId2: React.MutableRefObject<string>;
	setGameOver: React.Dispatch<React.SetStateAction<boolean>>;
	roomId: string;
	playerIndex: number;
	room: Room
}

const Game: React.FC<Props> = ({ score1, score2, userId1, userId2, setGameOver, roomId, playerIndex, room }) => {
	const canvasRef: any = useRef<HTMLCanvasElement>();
	const ball = useRef({ x: 0.5, y: 0.5 });
	const width = window.innerWidth - 100;
	const height = width / room.ratio;

	//initiate paddle positions
	const playerPaddle = useRef<{ x: number, y: number, w: number, h: number }>({
		x: (playerIndex === 0 ? 0.02 * width : 0.98 * width - room.paddle.width * width),
		y: width / 2,
		w: room.paddle.width * width,
		h: room.paddle.height * height,
	});
	const opponantPaddle = useRef<{ x: number, y: number, w: number, h: number }>({
		x: (playerIndex === 0 ? 0.98 * width - room.paddle.width * width : 0.02 * width),
		y: width / 2,
		w: room.paddle.width * width,
		h: room.paddle.height * height,
	});

	const powerUp = useRef<{
		active: boolean;
		x: number;
		y: number;
		text: string;
		width: number;
		height: number;
		color: string;
	}>({
		active: false,
		x: 0,
		y: 0,
		text: "",
		width: 0,
		height: 0,
		color: '#000000',
	});

	useEffect(() => {
		const canvas: any = canvasRef.current;
		const context = canvas.getContext('2d')!;

		const resizeCanvas = (): void => {
			canvas.width = window.innerWidth - 100;
			canvas.height = canvas.width / room.ratio;
			playerPaddle.current.x = (playerIndex === 0 ? 0.02 * canvas.width : 0.98 * canvas.width - room.paddle.width * canvas.width);
			// playerPaddle.current.y = 1 / 2 - 60;
			playerPaddle.current.w = room.paddle.width * canvas.width;
			playerPaddle.current.h = room.paddle.height * canvas.height;
			opponantPaddle.current.x = (playerIndex === 0 ? 0.98 * canvas.width - room.paddle.width * canvas.width : 0.02 * canvas.width)
			// opponantPaddle.current.y = 1 / 2 - 60;
			opponantPaddle.current.w = room.paddle.width * canvas.width;
			opponantPaddle.current.h = room.paddle.height * canvas.height;
			draw();
		}

		// Draw function render the game background, paddles and ball
		const draw = (): void => {

			// Clear the canvas
			context.clearRect(0, 0, canvas.width, canvas.height);

			// Draw the background
			room.isExpert ? context.fillStyle = '#edba44' : context.fillStyle = '#f491b0';
			context.fillRect(0, 0, canvas.width, canvas.height);

			// Draw the line in the middle of the background
			context.strokeStyle = '#000';
			// setLineDash([dashes length, space length])
			context.setLineDash([50, 20]);
			context.lineWidth = 5;
			context.beginPath();
			context.moveTo(canvas.width / 2, 0);
			context.lineTo(canvas.width / 2, canvas.height / 3);
			context.stroke();

			context.beginPath();
			context.moveTo(canvas.width / 2, (1.7 * canvas.height) / 3);
			context.lineTo(canvas.width / 2, canvas.height);
			context.stroke();

			// Draw the paddles
			context.fillStyle = '#000';
			context.fillRect(playerPaddle.current.x, playerPaddle.current.y, playerPaddle.current.w, playerPaddle.current.h);
			context.fillRect(opponantPaddle.current.x, opponantPaddle.current.y, opponantPaddle.current.w, opponantPaddle.current.h);

			// Draw the ball
			context.beginPath();
			context.arc(ball.current.x, ball.current.y, room.ball.radius * canvas.width, 0, Math.PI * 2, false);
			context.closePath();
			context.fill();

			// Draw the scores

			const fontSize = Math.min(canvas.width / 15, canvas.height / 15);
			const yRatio = 0.1;

			const yPosition = canvas.height * yRatio;
			const middleX = canvas.width / 2;

			const distanceFromMiddle = canvas.width * 0.1;

			const xPosition1 = middleX - distanceFromMiddle;
			const xPosition2 = middleX + distanceFromMiddle;

			context.textBaseline = 'bottom';

			context.font = `bold ${fontSize * 1.5}px "Bungee Shade", sans-serif`;
			let text = score1.current.toString();
			let textWidth = context.measureText(text).width;
			context.fillText(`${text}`, xPosition1 - textWidth, yPosition);

			text = score2.current.toString();
			textWidth = context.measureText(text).width;
			context.fillText(`${text}`, xPosition2, yPosition);

			context.beginPath();
			context.textAlign = 'center';
			context.fillStyle = 'rgba(0,0,0)';
			context.font = `bold ${fontSize * 2.5}px "Bungee Shade", sans-serif`;
			text = 'PONG';
			textWidth = context.measureText(text).width;
			context.fillText('PONG', canvas.width / 2, canvas.height / 2);

			// Draw the power-up if active
			if (powerUp.current.active) {
				context.beginPath();
				context.fillStyle = powerUp.current.color;
				context.arc(powerUp.current.x, powerUp.current.y, powerUp.current.width, 0, Math.PI * 2, false);
				context.stroke();

				context.beginPath();
				context.font = 'bold 20pt "Bungee Shade", sans-serif';
				context.fillStype = 'black';
				context.textBaseline = 'middle';
				context.fillText(powerUp.current.text, powerUp.current.x, powerUp.current.y);
			}
		};

		//Update the position of the paddles and the ball
		const update = (): void => {

			// Check if the paddles are still in the canvas
			if (playerPaddle.current.y <= 0) {
				playerPaddle.current.y = 0;
			} else if (playerPaddle.current.y >= canvas.height - playerPaddle.current.h) {
				playerPaddle.current.y = canvas.height - playerPaddle.current.h;
			}

			// if (gameIsOver.current)
			// 	setGameOver(true);

		};

		// Animate just animate the game
		const animate = (): void => {
			if (score1.current < 11 && score2.current < 11) {
				draw();
				update();
				requestAnimationFrame(animate);
			}
		};

		// Key released listener
		const handleMouseMove = (event: MouseEvent) => {
			const canvasBounds = canvas.getBoundingClientRect();
			const mouseY = event.clientY - canvasBounds.top;

			// Update the y-coordinate of the rectangle based on mouse position
			playerPaddle.current.y = Math.min(canvas.height - playerPaddle.current.h, Math.max(0, mouseY - playerPaddle.current.h / 2));
		};

		// Apply the hooks to the document
		canvas.addEventListener('mousemove', handleMouseMove);
		window.addEventListener('resize', resizeCanvas);
		animate();
		resizeCanvas();

		//every 10ms, send new paddle position
		setInterval(() => { //TODO add clearInterval() when connection ends
			socket.emit("move-paddle", roomId, localStorage.getItem("id"), {
				x: playerPaddle.current.x / canvas.width,
				y: playerPaddle.current.y / canvas.height
			}, (room: Room) => {
				opponantPaddle.current.x = room.players[1 - playerIndex].paddle.x * canvas.width;
				opponantPaddle.current.y = room.players[1 - playerIndex].paddle.y * canvas.height;
				ball.current.x = room.ball.x * canvas.width;
				ball.current.y = room.ball.y * canvas.height;
				if (room.bonus) {
					powerUp.current.active = true;
					powerUp.current.x = room.bonus.x * canvas.width;
					powerUp.current.y = room.bonus.y * canvas.height;
					powerUp.current.text = room.bonus.text;
					powerUp.current.color = room.bonus.color;
					powerUp.current.width = room.bonus.radius * canvas.width;
					powerUp.current.height = room.bonus.radius * canvas.width;
				} else {
					powerUp.current.active = false;
				}
			})
		}, 20);

		socket.on('update-scores', ({ players }) => {
			score1.current = players[0].score;
			score2.current = players[1].score;
			userId1.current = players[0].userId;
			userId2.current = players[1].userId;
		})

		socket.on('game-over', ({ gameOver }) => {
			// gameIsOver.current = gameOver;
			setGameOver(true);
		})

		// Clear the hooks when the component is unmounted
		return () => {
			canvas.addEventListener('mousemove', handleMouseMove);
			window.addEventListener('resize', resizeCanvas);
		};


	}, []);

	return (
		<div className="pong-container">
			<canvas ref={canvasRef} />
		</div>
	);
};

export default Game;