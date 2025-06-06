import '../../css/pageContent/Chat.css';
import React, { useEffect, useState } from 'react';
import axios from 'axios';
import Banner from '../Banner/Banner';
import { useNavigate } from 'react-router-dom';
import bcrypt from 'bcryptjs';
import { Message } from '../svgIcons';
import { socket } from '../App';
import { Invite } from './chat/Invite';
import { ActivityStatus } from './components/ActivityStatus';
import { UserList } from './chat/UserList';


interface Message {
	id: number;
	sender_id: number;
	sender_username: string;
	canal_id: number;
	receiver_id: number;
	content: string;
	timestamp: string;
}

enum ChannelType {
	public = 'public',
	protected = 'protected',
}

interface ChannelInfo {
	id: number;
	name: string;
	type: ChannelType;
	password: string;
	errorMessage?: string;
}

export interface User {
	id: number;
	username: string;
	avatar: string | null;
	exp: number;

	relationtoChannel: ChannelRelation[];
}

interface ChannelRelation {
	canal_id: number;
	user_id: number;
	is_joined: boolean;
	is_owner: boolean;
	is_admin: boolean;
	is_banned: boolean;
	is_muted: boolean;
}

export interface Block {
	blocking_id: number;
	blocked_id: number;
}

const ChatPage: React.FC = () => {

	const navigate = useNavigate();
	const [channels, setChannels] = useState<ChannelInfo[]>([]);
	const [messages, setMessages] = useState<Message[]>([]);
	const [users, setUsers] = useState<User[]>([]);

	const [loadingChannels, setLoadingChannels] = useState<boolean>(true);
	const [loadingUsers, setLoadingUsers] = useState<boolean>(true);

	const [selectedPrivateChannel, setSelectedPrivateChannel] = useState<ChannelInfo>({} as ChannelInfo);
	const [selectedChannel, setSelectedChannel] = useState<ChannelInfo | null>(null);
	const [selectedUser, setSelectedUser] = useState<User | null>(null);

	const [showPasswordModal, setShowPasswordModal] = useState<boolean>(false);
	const [passwordInput, setPasswordInput] = useState<string>('');
	const [inputText, setInputText] = useState<string>('')

	const [joinedChannels, setJoinedChannels] = useState<ChannelInfo[]>([]);
	const [nonJoinedChannels, setNonJoinedChannels] = useState<ChannelInfo[]>([]);

	const [showModal, setShowModal] = useState<boolean>(false);
	const [showSettingsModal, setShowSettingsModal] = useState<boolean>(false);
	const [showUserSettingsModal, setShowUserSettingsModal] = useState<boolean>(false);
	const [createRoom, setRoom] = useState({
		name: '',
		type: ChannelType.public,
		password: '',
	});

	const [relationtoChannel, setRelationtoChannel] = useState<ChannelRelation[]>([]);
	const [relations, setRelations] = useState<ChannelRelation[]>([]);
	const [blocks, setBlocks] = useState<Block[]>([]);

	const fetchData = async (url: string, setter: React.Dispatch<React.SetStateAction<any>>) => {
		try {
			const response = await axios.get(url);
			setter(response.data);
			return response.data;
		} catch (error) {
			console.log(error);
		}
	};

	const getBlocks = () => fetchData(`http://localhost:3660/blocks/${id}`, setBlocks);
	const getRelationtoChannel = () => fetchData(`http://localhost:3660/canal-user-relations/${id}`, setRelationtoChannel);
	const getRelations = () => fetchData(`http://localhost:3660/canal-user-relations/`, setRelations);

	const getId = () => {
		const id = localStorage.getItem("id");
		if (id) {
			return parseInt(id);
		}
		return 0;
	};

	const id = getId();
	const [username, setUsername] = useState<string>("");


	const getUserName = async () => {
		try {
			axios.get(`http://localhost:3660/users/${id}`)
				.then(function (response) {
					setUsername(response.data.username);
				})
				.catch(function (error) {
					console.log(error);
				});

		} catch (error) {
			console.log(error);
		}
	};

	useEffect(() => {
		getUserName();
		fetchUsers();
		fetchChannels();
		getRelations();
		getRelationtoChannel();

		socket.on('new-message', handleNewMessage);
		socket.on('update-room', handleUpdateChannels);
		socket.on('update-user', handleUpdateUsers);
		return () => {
			socket.off('new-message', handleNewMessage);
			socket.off('update-room', handleUpdateChannels);
			socket.off('update-user', handleUpdateUsers);
		};
	}, [selectedUser, selectedChannel]);



	const fetchUsers = async () => {
		try {
			const response = await axios.get('http://localhost:3660/users');
			setUsers(response.data);
			getBlocks();
			setLoadingUsers(false);
		} catch (error) {
			console.log(error);
		}
	};

	const fetchCanalMessages = async (canal: ChannelInfo) => {
		try {
			const response = await axios.get(`http://localhost:3660/messages/canal/${canal.id}`);
			const filteredMessages2 = response.data.filter((message: Message) => {
				const blocking = blocks.find((block) => block.blocking_id === id && block.blocked_id === message.sender_id);
				const blocked = blocks.find((block) => block.blocking_id === message.sender_id && block.blocked_id === id);
				return !blocking && !blocked;
			});
			setMessages(filteredMessages2);
		} catch (error) {
			console.log(error);
		}
	};

	const fetchUserMessages = async (user: User) => {
		try {
			const response = await axios.get(`http://localhost:3660/messages/user/${user.id}`);

			const filteredMessages = response.data.filter((message: Message) => ((message.receiver_id === user.id && message.sender_id === id) || (message.receiver_id === id && message.sender_id === user.id)));
			setMessages(filteredMessages);
		} catch (error) {
			console.log(error);
		}
	};


	const fetchChannels = async () => {
		try {
			const response = await axios.get('http://localhost:3660/canals');
			const channels = response.data;
			setChannels(response.data);
			setLoadingChannels(false);

			const response2 = await axios.get(`http://localhost:3660/canal-user-relations/${id}`);
			const joinedChannelsIds = response2.data.filter((relation: any) => relation.is_joined).map((relation: any) => relation.canal_id);
			const joinedChannels = channels.filter((channel: any) => joinedChannelsIds.includes(channel.id));
			const nonJoinedChannels = channels.filter((channel: any) => !joinedChannelsIds.includes(channel.id));
			setJoinedChannels(joinedChannels);
			setNonJoinedChannels(nonJoinedChannels);
		}
		catch (error) {
			console.log(error);
		}
	};

	const handleNewMessage = (message: Message) => {
		const blocking = blocks.find((block) => block.blocking_id === id && block.blocked_id === message.sender_id);
		if (blocking) {
			return;
		}
		if (selectedChannel) {
			message.canal_id === selectedChannel.id && setMessages((prevMessages) => [...prevMessages, message]);
		}
		else if (selectedUser && message.sender_id === selectedUser.id) {
			message.sender_id === selectedUser.id && setMessages((prevMessages) => [...prevMessages, message]);
		}
		else if (selectedUser && message.sender_id === id) {
			message.sender_id === id && setMessages((prevMessages) => [...prevMessages, message]);
		}
	};

	const handleUpdateChannels = () => {

		fetchChannels();
		getRelations();
		getRelationtoChannel();
	};

	const handleUpdateUsers = () => {
		getBlocks();
	};

	const handleSend = () => {
		if (inputText.trim() === '') {
			return;
		}
		if (selectedChannel) {
			axios.post(`http://localhost:3660/messages/canal`, {
				content: inputText,
				canal_id: selectedChannel.id,
				sender_id: id,
				sender_username: username,
			});

			socket.emit('message', {
				content: inputText,
				canal_id: selectedChannel?.id,
				sender_id: id,
				sender_username: username,
			});
		} else if (selectedUser) {
			axios.post(`http://localhost:3660/messages/user`, {
				content: inputText,
				sender_id: id,
				sender_username: username,
				receiver_id: selectedUser.id,
			});
			socket.emit('message', {
				content: inputText,
				sender_id: id,
				sender_username: username,
				receiver_id: selectedUser.id,
			});
		}
		setInputText('');
	};


	const handleKeyPress = (e: React.KeyboardEvent<HTMLInputElement>) => {
		if (e.key === 'Enter') {
			handleSend();
		}
	}

	const handleUserSelect = async (user: User) => {
		setSelectedChannel(null);
		setSelectedUser(user);
		fetchUserMessages(user);
	};


	const handleChannelSelect = async (room: ChannelInfo) => {
		setSelectedUser(null);
		setSelectedChannel(room);
		fetchCanalMessages(room);
	};

	const handleOpenModal = () => {
		setShowPasswordModal(true);
	};

	const handleSubmitPassword = async (room: ChannelInfo) => {
		if (passwordInput) {
			const passwordsMatch = await bcrypt.compare(passwordInput, room.password);

			if (passwordsMatch) {
				const updateChannelLists = () => {
					setJoinedChannels((prevChannels) => [...prevChannels, room]);
					setNonJoinedChannels((prevChannels) =>
						prevChannels.filter((channel) => channel.id !== room.id)
					);
					setSelectedChannel(room);
					setSelectedUser(null);
				}

				const joinChannelRelation = async () => {
					try {
						const response = await axios.post(`http://localhost:3660/canal-user-relations/`, {
							canalId: room.id,
							userId: id,
							isJoined: true,
							isOwner: false,
							isAdmin: false,
							isBanned: false,
							isMuted: false,
						});

						if (response.status !== 200) {
							await axios.patch(`http://localhost:3660/canal-user-relations/${room.id}/${id}`, {
								isJoined: true,
							});
						}
						updateChannelLists();
						console.log('API call successful');
					} catch (error) {
						await axios.patch(`http://localhost:3660/canal-user-relations/${room.id}/${id}`, {
							isJoined: true,
						});
						updateChannelLists();
					}
				}
				const fetchRoomMessages = async () => {
					try {
						const response = await axios.get(`http://localhost:3660/messages/canal/${room.id}`);
						setMessages(response.data);
					} catch (error) {
						console.log(error);
					}
				}

				setPasswordInput('');
				setShowPasswordModal(false);
				await joinChannelRelation();
				await fetchRoomMessages();
			}
			else {
				alert('Incorrect password');
			}
		}
	}


	const handleChannelJoin = async (room: ChannelInfo) => {
		const relation = relations.find((relation) => relation.user_id === id && relation.canal_id === room.id);
		if (relation?.is_banned) {
			alert('You are banned from this channel');
			return;
		}

		if (room.type === ChannelType.protected) {
			setSelectedPrivateChannel(room);
			handleOpenModal();
			return;
		}


		const updateChannelLists = () => {
			setJoinedChannels((prevChannels) => [...prevChannels, room]);
			setNonJoinedChannels((prevChannels) =>
				prevChannels.filter((channel) => channel.id !== room.id)
			);
			setSelectedChannel(room);
			setSelectedUser(null);
		}

		const joinChannelRelation = async () => {
			try {
				const response = await axios.post(`http://localhost:3660/canal-user-relations/`, {
					canalId: room.id,
					userId: id,
					isJoined: true,
					isOwner: false,
					isAdmin: false,
					isBanned: false,
					isMuted: false,
				});

				if (response.status !== 200) {
					await axios.patch(`http://localhost:3660/canal-user-relations/${room.id}/${id}`, {
						isJoined: true,
					});
				}
				updateChannelLists();
				console.log('API call successful');
			} catch (error) {
				await axios.patch(`http://localhost:3660/canal-user-relations/${room.id}/${id}`, {
					isJoined: true,
				});
				updateChannelLists();
			}
		}
		const fetchRoomMessages = async () => {
			try {
				const response = await axios.get(`http://localhost:3660/messages/canal/${room.id}`);
				setMessages(response.data);
			} catch (error) {
				console.log(error);
			}
		}

		await joinChannelRelation();
		await fetchRoomMessages();
	};


	const handleChannelLeave = async (room: ChannelInfo) => {
		const leaveChannelRelation = async () => {
			try {
				await axios.patch(`http://localhost:3660/canal-user-relations/${room.id}/${id}`, {
					isJoined: false,
					isOwner: false,
					isAdmin: false,
					isMutted: false,
				});
			} catch (error) {
				console.error('Error leaving channel relation:', error);
			}
		};

		const updateChannelListsAfterLeaving = () => {
			setJoinedChannels((prevChannels) =>
				prevChannels.filter((channel) => channel.id !== room.id)
			);
			setNonJoinedChannels((prevChannels) => [...prevChannels, room]);
		};

		const clearSelectedItems = () => {
			setMessages([]);
			setSelectedChannel(null);
			setSelectedUser(null);
		};

		await leaveChannelRelation();
		updateChannelListsAfterLeaving();
		clearSelectedItems();
	};


	const handleModalOpen = () => {
		setShowModal(true);
	};

	const handleModalClose = () => {
		setShowModal(false);
		setRoom({
			name: '',
			type: ChannelType.public,
			password: '',
		});
	};


	const handleModalSubmit = async () => {
		if (createRoom.name === '') {
			alert('Name cannot be empty');
			return;
		}
		if (channels.find((channel) => channel.name === createRoom.name)) {
			alert('Channel already exists');
			return;
		}
		if (createRoom.type === ChannelType.protected && createRoom.password === '') {
			alert('Password cannot be empty');
			return;
		}
		try {
			const response = await axios.post(`http://localhost:3660/canals`, {
				name: createRoom.name,
				type: createRoom.type,
				password: createRoom.password,
			});
			await axios.post(`http://localhost:3660/canal-user-relations/`, {
				canalId: response.data.id,
				userId: id,
				isOwner: true,
				isAdmin: true,
				isJoined: true,
				isBanned: false,
				isMuted: false,
			});
			handleModalClose();
			socket.emit('update-room');
		}
		catch (error) {
			console.log(error);
		}
	};


	const handleSettings = (room: ChannelInfo) => {
		setShowSettingsModal(true);
	};

	const handleUserSettings = (room: ChannelInfo) => {
		getRelations();
		setShowUserSettingsModal(true);
	};

	const handleSubmitSettings = async (room: ChannelInfo) => {
		try {
			const response = await axios.patch(`http://localhost:3660/canals/${room.id}`, {
				name: room.name,
				type: room.type,
				password: room.password,
			});
			console.log(response);
			setShowSettingsModal(false);
			socket.emit('update-room', {
				name: room.name,
				type: room.type,
				password: room.password,
			});
		}
		catch (error) {
			console.log(error);
		}
	};

	async function muteUser(selectedUser: User) {
		try {
			const response = await axios.patch(`http://localhost:3660/canal-user-relations/${selectedChannel?.id}/${selectedUser.id}`, {
				isMuted: true,
			});
			if (response.status === 200) {
				alert('User muted');
			}
			else {
				alert('Error muting user');
			}
			socket.emit('update-room');
		}
		catch {
			alert('Error muting user');
		}
		setShowUserSettingsModal(false);
	}

	async function banUser(selectedUser: User) {
		try {
			const response = await axios.patch(`http://localhost:3660/canal-user-relations/${selectedChannel?.id}/${selectedUser.id}`, {
				isBanned: true,
				isJoined: false,
			});
			if (response.status === 200) {
				alert('User banned');
			}
			else {
				alert('Error banning user');
			}
			socket.emit('update-room');

		}
		catch {
			alert('Error banning user');
		}
		setShowUserSettingsModal(false);
	}

	async function unbanUser(selectedUser: User) {
		try {
			const response = await axios.patch(`http://localhost:3660/canal-user-relations/${selectedChannel?.id}/${selectedUser.id}`, {
				isBanned: false,
			});
			if (response.status === 200) {
				alert('User unbanned');
			}
			else {
				alert('Error unbanning user');
			}
			socket.emit('update-room');
		}
		catch {
			alert('Error unbanning user');
		}
		setShowUserSettingsModal(false);
	}


	async function kickUser(selectedUser: User) {
		try {
			const response = await axios.patch(`http://localhost:3660/canal-user-relations/${selectedChannel?.id}/${selectedUser.id}`, {
				isJoined: false,
			});
			if (response.status === 200) {
				alert('User kicked');
			}
			else {
				alert('Error kicking user');
			}
			socket.emit('update-room');
		}
		catch {
			alert('Error kicking user');
		}
		setShowUserSettingsModal(false);
	}

	async function makeAdmin(selectedUser: User) {
		try {
			const response = await axios.patch(`http://localhost:3660/canal-user-relations/${selectedChannel?.id}/${selectedUser.id}`, {
				isAdmin: true,
			});
			if (response.status === 200) {
				alert('User made admin');
			}
			else {
				alert('Error making user admin');
			}
			socket.emit('update-room');
		}
		catch (error) {
			alert('Error making user admin');
		}
		setShowUserSettingsModal(false);
	}

	async function removeAdmin(selectedUser: User) {
		try {
			const response = await axios.patch(`http://localhost:3660/canal-user-relations/${selectedChannel?.id}/${selectedUser.id}`, {
				isAdmin: false,
			});
			if (response.status === 200) {
				alert('User removed as admin');
			}
			else {
				alert('Error removing user as admin');
			}
			socket.emit('update-room');
		}
		catch (error) {
			alert('Error removing user as admin');
		}
		setShowUserSettingsModal(false);
	}

	async function unmuteUser(selectedUser: User) {
		try {
			const response = await axios.patch(`http://localhost:3660/canal-user-relations/${selectedChannel?.id}/${selectedUser.id}`, {
				isMuted: false,
			});
			if (response.status === 200) {
				alert('User unmuted');
				socket.emit('update-room');
			}
			else {
				alert('Error unmuting user');
			}
		}
		catch (error) {
			alert('Error unmuting user');
		}
		setShowUserSettingsModal(false);
	}

	return (
		<>
			<Banner />
			<div className="chat-container">
				<div className="canals-list">
					<h2>Channels</h2>
					{loadingChannels ? (
						<p>Loading channels...</p>
					) : (
						<ul>
							{joinedChannels.map((room) => {
								return (
									<li key={room.id} onClick={() => handleChannelSelect(room)}>
										<span>{room.name}</span>
										<span>
											<button onClick={() => handleChannelLeave(room)}>Leave</button>
											{relationtoChannel.map((relation) => {
												if (relation.canal_id === room.id && relation.is_owner) {
													return (
														<button onClick={() => handleSettings(room)}>Settings</button>
													);
												}
											})}
											{relationtoChannel.map((relation) => {
												if (relation.canal_id === room.id && (relation.is_admin || relation.is_owner)) {
													return (
														<button onClick={() => handleUserSettings(room)}>Users</button>
													);
												}
											})}
										</span>
									</li>
								);
							})}
							<hr />
							{nonJoinedChannels.map((room) => {
								return (
									<li key={room.id}>
										<span>{room.name}</span>
										<button onClick={() => handleChannelJoin(room)}>Join</button>
									</li>
								);
							})}
						</ul>
					)}
					<button onClick={handleModalOpen}>Add Channel</button>
					{showModal && (
						<div className="modal">
							<div className="modal-content">
								<h2>Create Channel</h2>
								<div className="modal-inputs">
									<div className="input-labels">
										<label>Name:</label>
										<div className="input-fields">
											<input
												type="text"
												value={createRoom.name}
												onChange={(e) => setRoom({ ...createRoom, name: e.target.value })}
											/>
											{createRoom.type === ChannelType.protected && <label>Password:</label>}
											<label>Type:</label>
										</div>
										{createRoom.type === ChannelType.protected && (
											<input
												type="password"
												value={createRoom.password || ''}
												onChange={(e) => setRoom({ ...createRoom, password: e.target.value })}
											/>
										)}
										<select
											value={createRoom.type}
											onChange={(e) => setRoom({ ...createRoom, type: e.target.value as ChannelType })}
										>
											<option value={ChannelType.public}>public</option>
											<option value={ChannelType.protected}>protected</option>
										</select>
									</div>
								</div>
								<div className="modal-buttons">
									<button onClick={handleModalClose}>Cancel</button>
									<button onClick={handleModalSubmit}>Create</button>
								</div>
							</div>
						</div>
					)}
				</div>

				{showPasswordModal && (
					<div className="modal">
						<div className="modal-content">
							<h2>Enter Password</h2>
							<div className="modal-inputs">
								<input
									className="password-input"
									type="password"
									value={passwordInput}
									onChange={(e) => setPasswordInput(e.target.value)}
								/>
							</div>
							<div className="modal-buttons">
								<button onClick={() => setShowPasswordModal(false)}>Close</button>
								<button onClick={() => handleSubmitPassword(selectedPrivateChannel)}>Submit</button>
							</div>
						</div>
					</div>
				)}

				{showSettingsModal && (
					<div className="modal">
						<div className="modal-content">

							<h2>"{selectedChannel?.name}" Settings</h2>
							<div className="modal-inputs">

								<div className="input-labels">
									<label>Name:</label>
								</div>
								<div className="input-fields">
									<input
										type="text"
										value={selectedChannel?.name}
										onChange={(e) => setSelectedChannel((prevState) => ({
											...prevState!,
											name: e.target.value
										}))}
									/>
								</div>

								<div className="input-labels">
									<label>Type:</label>
								</div>
								<div className="input-fields">
									<select
										value={selectedChannel?.type}
										onChange={(e) => setSelectedChannel((prevState) => ({
											...prevState!,
											type: e.target.value as ChannelType
										}))}
									>
										<option value={ChannelType.public}>public</option>
										<option value={ChannelType.protected}>protected</option>
									</select>
								</div>

								{selectedChannel?.type === ChannelType.protected ? (
									<>
										<div className="input-labels">
											<label>Password:</label>
										</div>
										<div className="input-fields">
											<input
												type="password"
												onChange={(e) => setSelectedChannel((prevState) => ({
													...prevState!,
													password: e.target.value
												}))}
											/>
										</div>
									</>
								) : null}




							</div>
							<div className="modal-buttons">
								<button onClick={() => setShowSettingsModal(false)}>Close</button>
								<button onClick={() => handleSubmitSettings(selectedChannel as ChannelInfo)}>Submit</button>
							</div>
						</div>
					</div>
				)}

				{showUserSettingsModal && (
					<div className="modal">
						<div className="modal-content">
							<h2>"{selectedChannel?.name}" Settings</h2>

							<div className="modal-inputs">
								<div className="input-labels">
									<label>Select user:</label>
									<select onChange={(e) => setSelectedUser(users.find((user) => user.username === e.target.value) || null)}>
										<option value="">Select a user</option>
										{
											users.filter((user) => user.username !== username).map((user) => (
												relations.find((relation) => relation.user_id === user.id && relation.canal_id === selectedChannel?.id && (relation.is_joined || relation.is_banned) && !relation.is_owner) &&
												<option key={user.id} value={user.username}>{user.username}</option>
											))}
									</select>
								</div>
							</div>
							{
								selectedUser ? (
									<div className="modal-inputs">
										<div className="input-labels">
											<label>Actions:</label>
										</div>
										<div className="input-fields">
											{relations.find((relation) => relation.user_id === selectedUser.id && relation.canal_id === selectedChannel?.id && relation.is_admin) ? (
												<button onClick={() => removeAdmin(selectedUser)}>Remove Admin</button>
											) : (
												<button onClick={() => makeAdmin(selectedUser)}>Make Admin</button>
											)}
											{relations.find((relation) => relation.user_id === selectedUser.id && relation.canal_id === selectedChannel?.id && relation.is_banned) ? (
												<button onClick={() => unbanUser(selectedUser)}>Unban</button>
											) : (
												<button onClick={() => banUser(selectedUser)}>Ban</button>
											)}
											<button onClick={() => kickUser(selectedUser)}>Kick</button>
											{relations.find((relation) => relation.user_id === selectedUser.id && relation.canal_id === selectedChannel?.id && relation.is_muted) ? (
												<button onClick={() => unmuteUser(selectedUser)}>Unmute</button>
											) : (
												<button onClick={() => muteUser(selectedUser)}>Mute</button>
											)}

										</div>
									</div>
								) : null
							}
							<div className="modal-buttons">
								<button onClick={() => setShowUserSettingsModal(false)}>Close</button>
							</div>
						</div>
					</div>
				)}


				<div className="chat-messages">
					{selectedUser || (selectedChannel && relationtoChannel.find((relation) => relation.canal_id === selectedChannel.id && relation.user_id === id && relation.is_joined)) ? (
						<>
							<h1 className="chat-title">Chat</h1>
							<ul>
								{messages.sort((a, b) => a.timestamp > b.timestamp ? 1 : -1).map((message) => (
									<li className={`message ${message.sender_username === username ? 'current-user' : ''}`} key={message.id}>
										<div className="message-content">
											<span className="message-sender">{message.sender_username}:</span>
											<p>{message.timestamp}</p>
											<p>{message.content}</p>
										</div>
									</li>
								))}
							</ul>

							<div className="chat-input">
								{ // if user blocked selected user
									blocks.find((block) => block.blocking_id === id && block.blocked_id === selectedUser?.id) ? (
										<p style={{ color: 'red' }}>You have blocked this user</p>
									) :
										relationtoChannel.find((relation) => relation.canal_id === selectedChannel?.id && relation.user_id === id && relation.is_muted) ? (
											<p style={{ color: 'red' }}>You are muted in this channel</p>
										) : (
											<><input
												className="chat-input"
												type="text"
												placeholder="Type your message..."
												value={inputText}
												onChange={(e) => setInputText(e.target.value)}
												onKeyPress={handleKeyPress} />
												<button onClick={handleSend}>Send</button></>
										)
								}
							</div>
						</>
					) : (
						<p>No user or channel selected.</p>
					)}
				</div>

				<UserList loadingUsers={loadingUsers} users={users} blocks={blocks} username={username} handleUserSelect={handleUserSelect} />
			</div>
		</>
	);
}


export default ChatPage;