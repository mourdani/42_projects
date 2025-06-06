import axios from "axios";
import { useNavigate } from "react-router-dom";
import { useEffect, useState } from "react";

export default function PlayerInfo(props: { id: string }) {
	const [user, setUser] = useState<{ user: { username: string, id: number, exp: number }, avatar: string }>();
	const navigate = useNavigate();

	useEffect(() => {
		getInfo();
	}, [])

	function getInfo() {
		console.log('http://localhost:3660/users/' + props.id);
		axios.get('http://localhost:3660/users/' + props.id)
			.then(function (response1) {
				if (response1.data.avatar) {
					axios.get('http://localhost:3660/file/' + response1.data.avatar, {
						responseType: 'blob'
					})
						.then(function (response2) {
							setUser({
								user: response1.data,
								avatar: URL.createObjectURL(response2.data)
							})
						})
						.catch(function (error) { console.log(error); })
				} else {
					setUser({
						user: response1.data,
						avatar: "../avatars/default.jpg"
					})
				}
			})
			.catch(function (error) {
				console.log(error);
				navigate("/");
			});
	}

	if (typeof user === 'undefined') {
		return (<div>Loading...</div>)
	}

	return (
		<div id="player-info">
			<div className="player-username">{user.user.username}</div>
			<img className="player-avatar" alt="avatar" src={user.avatar} />
		</div>
	)
}