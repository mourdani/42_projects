import React from 'react';
import './../../../css/pageContent/Game/Game.css';
import './../../../css/pageContent/Game/EndGame.css';
import PlayerInfo from "../components/PlayerInfo";

interface Props {
    onReplay: () => void;
    score1: number;
    score2: number;
    userId1: string;
    userId2: string;
}

const EndGame: React.FC<Props> = ({ onReplay, score1, score2, userId1, userId2}) => {

    return (
        <div className="end-game-container">
            <div className="players-info">
                <div className="player-recap">
                    < PlayerInfo id={userId1} />
                    <div className="score">{score1}</div>
                </div>
                <div className="player-recap">
                    < PlayerInfo id={userId2} />
                    <div className="score">{score2}</div>
                </div>
            </div>
            <div className="mode-buttons">
                <button className="mode-button" onClick={() => onReplay()}>Continue</button>
            </div>
        </div>
    );
};

export default EndGame;