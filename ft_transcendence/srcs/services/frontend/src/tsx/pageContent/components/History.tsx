import axios from "axios";
import { useState } from "react";
import { Link } from "react-router-dom";
import { useEffect } from "react";
import "../../../css/pageContent/component/History.css"

type match = {
	match_id: number,
	winner_id: number,
	loser_id: number,
	winner_score: number,
	loser_score: number,
	winner_user: {
		id: number;
		username: string;
		avatar: string;
		exp: number;
	},
	loser_user: {
		id: number;
		username: string;
		avatar: string;
		exp: number;
	}
}

export default function History(props: { id: string }) {
	const [history, setHistory] = useState<match[]>([]);

	function MatchUser(props: { id: string, username: string }) {
		return (
			<Link
				to={"/user_page/" + props.id}
				className="match-member"
			>
				{props.username}
			</Link>
		)
	}

	useEffect(() => {
		axios.get('http://localhost:3660/game/history/' + props.id)
			.then(function (value) {
				setHistory(value.data);
			})
			.catch(function (error) {
				console.log(error);
			})
	}, [props.id]);

	if (!history) {
		return <>loading</>;
	}
	if (history.length === 0) {
		return (
			<div>No match played yet</div>
		)
	}
	return (
		<div className="match-list">
			{history.map((match) => (
				<div
					className={"match"}
					style={{ backgroundColor: (+props.id === match.winner_id) ? "#419140" : "#ba2323" }}
					key={"match-" + match.match_id}
				>
					<MatchUser username={match.winner_user.username} id={match.winner_id.toString()} />
					<div className="match-score">{match.winner_score}/{match.loser_score}</div>
					<MatchUser username={match.loser_user.username} id={match.loser_id.toString()} />
				</div>
			))}
		</div>
	)
}
