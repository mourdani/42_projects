import { useEffect, useState } from "react";
import { Cross } from "../../svgIcons";
import { socket } from "../../App";

export interface Achievement {
	achievement_id: number,
	name: string,
	description: string
}

export function AchievementPopUp() {
	const [achievements, setAchievements] = useState<Array<Achievement>>([]);

	useEffect(() => {
		socket.on('earn-achievements', (achievements: Array<Achievement>) => {
			console.log("ACHIEVEMENTS:");
			console.log(achievements);
			setAchievements(achievements);
		});
	}, []);

	function close(e: React.FormEvent, id: number) {
		e.stopPropagation();
		setAchievements(achievements.filter((achievement: Achievement) => achievement.achievement_id !== id));
	}

	return (
		<div>
			{achievements.length === 0 ? <></> : <div className="popup-background"></div>}
			{achievements.map((achievement: Achievement) =>
				<div
					className="popup"
					id={"popup-" + achievement.achievement_id}
				>
					<div onClick={(e) => { close(e, achievement.achievement_id) }}>
						<Cross className="popup-cross" color="black" />
					</div>
					<div className="achievement-disclaimer">You have earned an achievement:</div>
					<div className="popup-achievement-name">
						{achievement.name}
					</div>
					<div className="popup-achievement-description">
						{achievement.description}
					</div>
				</div>
			)
			}
		</div >
	)
}