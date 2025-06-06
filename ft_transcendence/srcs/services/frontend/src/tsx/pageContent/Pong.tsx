import React, { useEffect, useRef, useState } from 'react';
import './../../css/pageContent/Game/Game.css';
import './../../css/pageContent/Game/Pong.css';
import Lobby from './Game/Lobby';
import StartGame from './Game/StartGame';
import EndGame from './Game/EndGame';
import Banner from "../Banner/Banner";
import { socket } from '../App';
import { useNavigate, useParams } from 'react-router-dom';

const Pong: React.FC = () => {

	const [gameStarted, setGameStarted] = useState<boolean>(false);
	const [gameOver, setGameOver] = useState<boolean>(false);
	const [selectedMode, setSelectedMode] = useState<string>('');
	const navigate = useNavigate();
	let score1 = useRef<number>(0);
	let score2 = useRef<number>(0);
	let userId1 = useRef<string>("");
	let userId2 = useRef<string>("");
	let { roomId } = useParams();

	useEffect(() => {
		if (roomId !== undefined) {
			setSelectedMode('easy');
			setGameStarted(true);
		}

		socket.on("invite-accepted", (roomId: string, callback) => {
			setSelectedMode('easy');
			setGameStarted(true);
		})

	}, [])

	useEffect(() => {

		if (gameOver && roomId !== undefined) {
			navigate("/pong");
		}

		return () => {
			socket.emit('leaving-pong');
		};
	}, [gameStarted, gameOver]);

	if (gameOver) {
		return (
			<>
				<Banner />
				<div className="Pong">
					<EndGame
						score1={score1.current}
						score2={score2.current}
						userId1={userId1.current}
						userId2={userId2.current}
						onReplay={() => {
							score1.current = 0;
							score2.current = 0;
							setGameOver(false);
							setGameStarted(false);
						}}
					/>
				</div>
			</>
		);
	} else if (!gameStarted) {
		return (
			<>
				<Banner />
				<div className="Pong">
					<StartGame onModeSelect={(mode) => {
						setSelectedMode(mode);
						setGameStarted(true); // Start the game when a mode is selected
					}} />
				</div>
			</>
		);
	}

	return (
		<>
			<Banner />
			<div className="PongWinScore">
				<Lobby
					score1={score1}
					score2={score2}
					userId1={userId1}
					userId2={userId2}
					setGameOver={setGameOver}
					setGameStarted={setGameStarted}
					selectedMode={selectedMode}
					paramRoomId={roomId}
				/>
			</div>
		</>
	);

};

export default Pong;