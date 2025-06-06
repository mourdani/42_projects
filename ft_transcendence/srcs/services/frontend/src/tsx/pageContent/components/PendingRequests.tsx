import { useEffect, useState } from "react";
import axios from "axios";
import { useNavigate } from "react-router-dom";
import { Check, Cross, Clock } from "../../svgIcons";
import "../../../css/pageContent/UserPage/PendingRequest.css"
import { acceptRequest, removeRelation } from "../../requests";

type user = {
	id: number,
	username: string,
	avatar: string,
	exp: number
}

type relation = {
	relating_id: number,
	related_id: number,
	relation: string,
	related_user: user
}

export default function PendingRequest() {
	const [requests, setRequests] = useState<relation[]>();
	const navigate = useNavigate();

	function getRequests() {
		axios.get('http://localhost:3660/users/pending/' + localStorage.getItem("id"))
			.then(function (response) {
				setRequests(response.data);
			})
			.catch(function (error) { console.log(error) })
	}

	useEffect(() => {
		getRequests();
	}, [])

	if (!requests) {
		return (<>Loading...</>);
	}
	if (requests.length === 0) {
		return (<>No pending requests</>)
	}


	function Buttons(props: { id: number, relation: string }) {
		if (props.relation === 'R') {
			return (
				<div className="request-buttons">
					<div
						className="request-button"
						onClick={function (e) {
							e.stopPropagation();
							acceptRequest(props.id)
								.then(function () { getRequests() });
						}}
					>
						<Check className="request-button" color="#ffffff" />
					</div>
					<div
						className="request-button"
						onClick={function (e) {
							e.stopPropagation();
							removeRelation(props.id)
								.then(function () { getRequests() });
						}}
					>
						<Cross className="request-button" color="#ffffff" />
					</div>
				</div>
			)
		} else {
			return (
				<div className="request-buttons">
					<div
						onClick={function (e) {
							e.stopPropagation();
							removeRelation(props.id)
								.then(function () { getRequests() });
						}}
						className="request-button"
					>
						<Clock className="request-button" color="#ffffff" />
					</div>
				</div>
			)
		}
	}

	function FriendRequest(props: { relation: relation }) {
		const [avatar, setAvatar] = useState("../avatars/default.jpg")

		if (props.relation.related_user.avatar) {
			axios.get('http://localhost:3660/file/' + props.relation.related_user.avatar, {
				responseType: 'blob'
			})
				.then(function (response) {
					setAvatar(URL.createObjectURL(response.data));
				})
				.catch(function (error) { console.log(error); })
		}
		return (
			<div
				className="friend"
				onClick={function (event) {
					event.stopPropagation();
					navigate("/user_page/" + props.relation.related_user.id)
				}}
				key={"friend-request-" + props.relation.related_id}
			>
				<img className="friend-avatar" src={avatar} />
				<div className="friend-username">
					{props.relation.related_user.username}
				</div>
				<Buttons id={props.relation.related_id} relation={props.relation.relation} />
			</div>
		)
	}

	return (
		<div>
			{requests.map((request: relation) => (
				<FriendRequest key={"friend-request-" + request.related_id} relation={request} />
			))}
		</div>
	);
}