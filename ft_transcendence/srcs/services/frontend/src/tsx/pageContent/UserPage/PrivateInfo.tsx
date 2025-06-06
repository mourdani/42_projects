import { useState } from "react";
import "../../../css/pageContent/UserPage/PrivateInfo.css"
import History from "../components/History";
import Achievements from "../components/Achievements";
import Friends from "../components/Friends";
import PendingRequest from "../components/PendingRequests";
import axios from "axios";
import { useEffect } from "react";

export default function PrivateInfo(props: { isFriend: boolean | undefined, id: string }) {
	const [showPage, setShowPage] = useState(false);
	const [blockStatus, setBlockStatus] = useState({ blocked: true, blocking: false });

	useEffect(() => {
		axios
			.get("http://localhost:3660/relations/" + localStorage.getItem("id") + "/" + props.id + "/blocked")
			.then(function (response) {
				setBlockStatus(response.data);
			})
			.catch(function (error) {
				console.log(error);
			});
	}, []);


	if (!blockStatus) {
		return <></>
	}
	if (blockStatus.blocking && !showPage) {
		return (
			<div>
				<div>You have blocked this user. Would you like to see this page anyway?</div>
				<button onClick={function () { setShowPage(true) }}>Show page</button>
			</div>
		)
	}
	if (localStorage.getItem("id") !== props.id && blockStatus.blocked) {
		return (
			<div>
				<div>You are blocked by this user.</div>
			</div>
		)
	}

	if ((props.isFriend === undefined || !props.isFriend) && localStorage.getItem("id") !== props.id) {
		return <></>;
	}


	function Pendings() {
		return (
			<div className="pending">
				<h2>Pending requests</h2>
				<PendingRequest />
			</div>
		)
	}
	return (
		<div className="user-data">
			<div className="history">
				<h2>Match history</h2>
				<History id={props.id} />
			</div>
			<div className="achievements">
				<h2>Achievements</h2>
				<Achievements id={props.id} />
			</div>
			<div className="friends">
				{props.id === localStorage.getItem("id") ? <Pendings /> : <></>}
				<div>
					<h2>Friend list</h2>
					<Friends id={props.id} />
				</div>
			</div>
		</div>
	)
}
