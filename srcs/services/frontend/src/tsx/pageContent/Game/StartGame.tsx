import React from 'react';
import './../../../css/pageContent/Game/Game.css';
import './../../../css/pageContent/Game/StartGame.css';

interface Props {
    onModeSelect: (mode: string) => void;
}

const StartGame: React.FC<Props> = ({ onModeSelect }) => {
    return (
        <div className="start-game-container">
            <h1 className="game-title">PONG</h1>
            <div className="mode-buttons">
                <button className="mode-button" onClick={() => onModeSelect('easy')}>Easy</button>
                <button className="mode-button" onClick={() => onModeSelect('expert')}>Expert</button>
            </div>
        </div>
    );
};

export default StartGame;
