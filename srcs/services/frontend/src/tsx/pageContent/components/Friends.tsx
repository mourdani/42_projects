import axios from "axios";
import { useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";
import "../../../css/pageContent/component/Friends.css"

type user = {
	id: number,
	username: string,
	avatar: string,
	exp: number
}

type friend = {
	relating_id: number,
	related_id: number,
	relation: string,
	related_user: user
}

export default function Friends(props: { id: string }) {
	const [friends, setFriends] = useState<friend[]>();
	const navigate = useNavigate();

	useEffect(() => {
		axios.get('http://localhost:3660/users/friends/' + props.id)
			.then(function (value) {
				setFriends(value.data);
			})
			.catch(function (error) {
				console.log(error);
			})
	}, [props.id]);

	if (!friends) {
		return <>loading</>;
	}
	if (friends.length === 0) {
		return (
			<div>No friends</div>
		)
	}

	function Friend(props: { user: user }) {
		const [avatar, setAvatar] = useState("../avatars/default.jpg")

		useEffect(() => {
			if (props.user.avatar) {
				axios.get('http://localhost:3660/file/' + props.user.avatar, {
					responseType: 'blob'
				})
					.then(function (response) {
						setAvatar(URL.createObjectURL(response.data));
					})
					.catch(function (error) { console.log(error); })
			}
		}, [])

		return (
			<div
				className="friend"
				onClick={function (event) { navigate("/user_page/" + props.user.id) }}
			>
				<img className="friend-avatar" src={avatar} />
				<div className="friend-username">
					{props.user.username}
				</div>
			</div>
		)
	}

	return (
		<div>
			<div className="friend-list">
				{friends.map((friend: friend) => (
					<Friend key={"friend-" + friend.related_id} user={friend.related_user} />
				))}
			</div>
		</div>
	)
}