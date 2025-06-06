import Banner from "../Banner/Banner"
import "../../css/pageContent/PageContent.css"
import { useState, useEffect } from "react";
import axios from "axios";
import "../../css/pageContent/Leaderboard.css";
import { useNavigate } from "react-router-dom";
import ProgressBar from "./components/ProgressBar"


export default function Leaderboard() {
	const navigate = useNavigate();

	function LeaderboardUser(props: { user: { id: string, username: string, avatar: string, exp: number }, index: number }) {
		const user = props.user;
		const [avatar, setAvatar] = useState("../avatars/default.jpg")

		useEffect(() => {
			if (user.avatar) {
				axios.get('http://localhost:3660/file/' + user.avatar, {
					responseType: 'blob'
				})
					.then(function (response) {
						setAvatar(URL.createObjectURL(response.data));
					})
					.catch(function (error) { console.log(error); })
			}
		}, [])

		return (<div
			className="result-item"
			id={user.id}
			onClick={function (event) { navigate("/user_page/" + user.id) }}
		>
			<div className="index">#{props.index + 1}</div>
			<img className="leaderboard-avatar" src={avatar} /> {/* replace wiht returned avatar */}
			<div className="leaderboard-username">{user.username}</div>
			<ProgressBar className="level" exp={user.exp} />
		</div>
		)
	}

	function Leaderboard() {
		const [list, setList] = useState([]);

		if (list.length === 0) {
			axios.get('http://localhost:3660/users/leaderboard/')
				.then(function (value) {
					setList(value.data)
				})
				.catch(function (error) { console.log(error) });
		}
		if (list.length === 0) {
			return (<div>loading...</div>)
		}
		return (
			<div className="leaderboard">
				{list.map((user: { id: string, username: string, avatar: string, exp: number }, index) =>
					(<LeaderboardUser key={"leaderboard-" + user.id} user={user} index={index} />)
				)}
			</div>
		);
	}

	return (
		<>
			<Banner />
			<div className="page">
				<h1>Leaderboard</h1>
				<div>
					<Leaderboard />
				</div>
			</div>
		</>
	)
}