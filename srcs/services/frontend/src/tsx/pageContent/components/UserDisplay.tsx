import ProgressBar from "./ProgressBar"
import axios from "axios";
import { useEffect, useState } from "react";
import { ActivityStatus } from "./ActivityStatus";

export default function UserDisplay(props: { id: string }) {
	const [user, setUser] = useState<{ user: { username: string, id: number, exp: number }, avatar: string }>();

	useEffect(() => {
		getInfo();
	}, [])

	function getInfo() {
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
			});
	}

	if (typeof user === 'undefined') {
		return (<div>Loading...</div>)
	}

	return (
		<div className="up-user-display" id="user-info">
			<img className="up-avatar" alt="avatar" src={user.avatar} />
			<div>
				<div className="up-username">{user.user.username}</div>
				<ActivityStatus width={15} id={props.id} />
			</div>
			<ProgressBar className="up-progress-bar" exp={user.user.exp} />
		</div>
	)
}