import { useState, useRef } from "react";
import { Cross } from "../../svgIcons";
import { Check } from "../../svgIcons";
import UserDisplay from "./UserDisplay";
import { socket } from "../../App";
import "../../../css/pageContent/component/popup.css"

export function InvitePopup() {
	const [numberInvites, setNumberInvites] = useState<number>(0);
	const [invites, setInvites] = useState<{ id: string, roomId: string }[]>([]);
	console.log(invites);

	socket.on("invited", (id: string, roomId: string) => {
		invites.push({ id, roomId });
		console.log(invites);
		setNumberInvites(numberInvites + 1);
	});

	socket.on("uninvited", (id: string, callback) => {
		console.log("uninvited by", id);
		setInvites(invites.filter((item) => item.id !== id));
		setNumberInvites(numberInvites - 1);
	})

	socket.on("log-out", (id: string) => {
		setInvites(invites.filter((item) => item.id !== id));
	})

	function acceptInvite(id: string, roomId: string) {
		invites.forEach((value) => {
			if (value.id !== id)
				socket.emit("refuse-invite", value.id, value.roomId);
		})
		setInvites([]);
		setNumberInvites(0);
		socket.emit("accept-invite", id, roomId, () => { });
	}

	function refuseInvite(id: string, roomId: string) {
		socket.emit("refuse-invite", id, roomId);
		setInvites(invites.filter((item) => item.id !== id))
		setNumberInvites(numberInvites - 1);
	}

	return (
		<div>
			{invites.length === 0 ? <></> : <div className="popup-background"></div>}
			{invites.map((item: { id: string, roomId: string }) =>
				<div
					className="popup"
					id={"popup-invite-" + item.id}
				>
					<p>This user wants to play with you</p>
					<div className="popup-user">
						<UserDisplay id={item.id} />
					</div>
					<div className="invite-reply-buttons">
						<div className="refuse-invite" onClick={(e) => refuseInvite(item.id, item.roomId)}>
							<Cross className="" color="#9e150b" />
						</div>
						<div className="accept-invite" onClick={(e) => acceptInvite(item.id, item.roomId)}>
							<Check className="accept-invite" color="#055c06" />
						</div>
					</div>
				</div>
			)}
		</div >
	);
}