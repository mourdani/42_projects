import { User } from "../Chat";
import { socket } from "../../App";
import { useState } from "react";
import { Clock } from "../../svgIcons";

export function Invite(props: { user: User, inviteSent: boolean, setInviteSent: React.Dispatch<React.SetStateAction<boolean>> }) {
	const [invitable, setInvitable] = useState(false);
	const [waiting, setWaiting] = useState(false);
	const [selectMode, setSelectMode] = useState(false);
	const strId = (props.user.id).toString(10);

	//all this handle whether or not invite can be sent
	socket.emit("user-status", strId, (status: number) => {
		if (status === 1) { //logged in
			setInvitable(true);
		}
	})

	socket.on('log-out', (id: string) => {
		if (id === strId) {
			setInvitable(false);
		}
	})

	socket.on('log-in', (id: string) => {
		if (id === strId) {
			setInvitable(true);
		}
	})

	socket.on('in-game', (id: string) => {
		if (id === strId) {
			setInvitable(false);
		}
	})

	//send invite
	function handleInvite(e: React.MouseEvent<HTMLElement>, isExpert: boolean) {
		e.stopPropagation();
		console.log(strId);
		socket.emit('invite', localStorage.getItem("id"), strId, isExpert, () => { //replace with difficulty
			setWaiting(true);
		});
		props.setInviteSent(true);
	}

	//unsend invite
	function handleUninvite(e: React.MouseEvent<HTMLElement>) {
		e.stopPropagation();
		socket.emit('uninvite', localStorage.getItem("id"), strId, () => { });
		setWaiting(false);
		setSelectMode(false);
		props.setInviteSent(false);
	}

	socket.on("invite-refused", (callback) => {
		setWaiting(false);
		setSelectMode(false);
		props.setInviteSent(false);
	});

	if (waiting) {
		return (<div onClick={handleUninvite}>
			<Clock className="invite-button" color="#000000" />
		</div>)
	}

	if (selectMode) {
		return (
			<div>
				<button onClick={(e) => handleInvite(e, false)}>Easy</button>
				<button onClick={(e) => handleInvite(e, true)}>Expert</button>
				<button onClick={(e) => { e.stopPropagation(); setSelectMode(false) }}>Cancel</button>
			</div >
		)
	}

	return (invitable && !props.inviteSent) ? <button
		onClick={(e) => { e.stopPropagation(); setSelectMode(true); }}
	>Invite</button> : <></>
}