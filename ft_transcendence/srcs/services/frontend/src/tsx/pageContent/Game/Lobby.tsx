import React, { useEffect, useState, useRef } from 'react';
import './../../../css/pageContent/Game/Lobby.css';
import Game, { Player } from "./Game";
import PlayerInfo from "../components/PlayerInfo";
import LoadingDots from "../components/LoadingDots";
import { Room } from './Game';
import { socket } from '../../App';
import { useNavigate } from 'react-router-dom';


interface Props {
	score1: React.MutableRefObject<number>;
	score2: React.MutableRefObject<number>;
	userId1: React.MutableRefObject<string>;
	userId2: React.MutableRefObject<string>;
	setGameOver: React.Dispatch<React.SetStateAction<boolean>>;
	setGameStarted: React.Dispatch<React.SetStateAction<boolean>>;
	selectedMode: string;
	paramRoomId: string | undefined;
}

const Lobby: React.FC<Props> = ({ score1, score2, userId1, userId2, setGameOver, setGameStarted, selectedMode, paramRoomId }) => {
	const [roomId, setRoomId] = useState("");
	const [shouldRenderGame, setShouldRenderGame] = useState(false);
	const [players, setPlayers] = useState<Array<Player>>([]);
	const room = useRef<Room>();
	const navigate = useNavigate();

	useEffect(() => {
		console.log("paramRoomId", paramRoomId);
		socket.emit("create-room", selectedMode === 'expert', localStorage.getItem("id")!, paramRoomId, (room: string) => {
			setRoomId(room);
			console.log(room);
		});

		socket.on('player-joined', (joinedRoom: Room) => {
			console.log(joinedRoom.players);
			room.current = joinedRoom;
			setPlayers(joinedRoom.players);
		});

		socket.on('opponent-left', () => {
			alert('Opponent left');
			setPlayers([]);
			setGameStarted(false);
			score1.current = 0;
			score2.current = 0;
			if (paramRoomId !== undefined) {
				navigate("/pong")
			}
		});

		socket.on('game-start', () => {
			setShouldRenderGame(true);
		})
	}, []);

	function Countdown() {
		const [countdown, setCountdown] = useState(3);

		socket.on('countdown', (i) => {
			setCountdown(i);
		})
		return <div className="countdown">{countdown}</div>
	}

	function UserTest() {
		return (
			<div className="players-info">
				< PlayerInfo id={players[0].userId} />
				<Countdown />
				< PlayerInfo id={players[1].userId} />
			</div>
		)
	}

	if (players.length < 2) {
		return (
			<div className="lobby-container">
				<h1 className="game-title">PONG</h1>
				<div className="players-info">
					< PlayerInfo id={localStorage.getItem("id")!} />
					<div className="player-info">
						<div className="waiting-opponent">Opponent</div>
						<LoadingDots />
					</div>
				</div>
			</div>
		);
	}
	else if (!shouldRenderGame) {
		return (
			<div className="lobby-container">
				<h1 className="game-title">PONG</h1>
				<UserTest />
			</div>
		);
	}
	else {
		return (
			<>
				<Game
					score1={score1}
					score2={score2}
					userId1={userId1}
					userId2={userId2}
					setGameOver={setGameOver}
					roomId={roomId}
					playerIndex={players[0].userId === localStorage.getItem("id") ? 0 : 1}
					room={room.current!}
				/>
			</>
		);
	}
}

export default Lobby;