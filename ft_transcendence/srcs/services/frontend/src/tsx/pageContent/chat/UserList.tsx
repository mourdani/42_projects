import { User } from "../Chat";
import axios from "axios";
import { Block } from "../Chat";
import { Invite } from "./Invite";
import { ActivityStatus } from "../components/ActivityStatus";
import { socket } from "../../App";
import { useNavigate } from "react-router-dom";
import { useState } from "react";

export function UserList(props: { loadingUsers: boolean, users: User[], blocks: Block[], username: string, handleUserSelect: any }) {
	const navigate = useNavigate();
	const [inviteSent, setInviteSent] = useState(false);

	async function handleUnblockUser(selectedUser: User) {
		try {
			const response = await axios.delete(`http://localhost:3660/relations/${localStorage.getItem("id")}/${selectedUser.id}/block`);
			if (response.status === 200) {
				alert('User unblocked');
			}
			else {
				alert('Error unblocking user');
			}
			socket.emit('update-user');
		}
		catch (error) {
			alert('Error unblocking user');
		}
	}

	async function handleBlockUser(selectedUser: User) {
		try {
			const response = await axios.post(`http://localhost:3660/relations/${localStorage.getItem("id")}/${selectedUser.id}/block`);
			if (response.status === 201) {
				alert('User blocked');
			}
			else {
				alert('Error blocking user');
			}
			socket.emit('update-user');

		}
		catch (error) {
			alert('Error blocking user');
		}
	}

	const handleShowProfile = (user: User) => {
		navigate(`/user_page/${user.id}`);
	};

	return (
		<div className="users-list">
			<h2>Users</h2>
			{props.loadingUsers ? (
				<p>Loading users...</p>
			) : (
				<ul>
					{
						props.users.filter((user) => !props.blocks.find((block) => block.blocking_id === user.id)).map((user) => {
							if (props.username !== user.username) {
								return (
									<li key={user.id} onClick={() => props.handleUserSelect(user)}>
										<ActivityStatus id={(user.id).toString(10)} width={10} />
										<span >{user.username}</span>
										<div >
											{props.blocks.find((block) => block.blocked_id === user.id) ? (
												<button onClick={() => handleUnblockUser(user)}>Unblock</button>
											) : (
												<button onClick={() => handleBlockUser(user)}>Block</button>
											)}
											<button onClick={() => handleShowProfile(user)}>Profile</button>
											<Invite user={user} inviteSent={inviteSent} setInviteSent={setInviteSent} />
										</div>
									</li>
								);
							} else {
								return null;
							}
						})}
				</ul>
			)}
		</div>
	)
}