import { useState } from "react";
import axios from "axios";
import { useEffect } from "react";
import '../../../css/pageContent/component/Achievements.css'

type achievement = {
	achievement: {
		achievement_id: number;
		name: string;
		description: string;
	},
	user_id: number;
	achievement_id: number;
}

export default function Achievements(props: { id: string }) {
	const [achievements, setAchievements] = useState<achievement[]>([]);

	useEffect(() => {
		axios.get('http://localhost:3660/game/achievements/' + props.id)
			.then(function (value) {
				setAchievements(value.data);
			})
			.catch(function (error) {
				console.log(error);
			})
	}, [props.id]);

	if (!achievements) {
		return <>loading</>;
	}
	if (achievements.length === 0) {
		return (
			<div>No achievements earned yet</div>
		)
	}
	return (
		<div className="achievement-list">
			{achievements.map((achievement) => (
				<div
					className="achievement"
					key={"achievement-" + achievement.achievement_id}
				>
					<div className="achievement-name">{achievement.achievement.name}</div>
					<div className="achieve,emt-description">{achievement.achievement.description}</div>
				</div>
			))}
		</div>
	)
}