import { useState } from "react";
import { UpArrow, DownArrow } from '../svgIcons';
import axios from 'axios';
import { Link, useNavigate } from "react-router-dom";
import { socket } from "../App";

export function Menu() {
	const [username, setUsername] = useState("");
	const [avatar, setAvatar] = useState("../avatars/default.jpg");
	const [showMenu, setShowMenu] = useState(false);
	const navigate = useNavigate();
	const Arrow = () => {
		if (showMenu) {
			return <UpArrow className="arrow" />;
		} else {
			return <DownArrow className="arrow" />;
		}
	}

	function LogOut() {
		let id = localStorage.getItem("id");
		if (id !== undefined && id !== null) {
			socket.emit("log-out", id);
		}
		localStorage.clear();
		navigate("/login")
	}

	function Options() {
		if (!showMenu) {
			return ("");
		}
		return (
			<div className="options">
				<div className="option-box">
					<Link className="option" to={"/pong"}>Play</Link>
				</div>
				<div className="option-box">
					<Link className="option" to={"/chat"}>Chat</Link>
				</div>
				<div className="option-box">
					<Link className="option" to={"/leaderboard"}>Leaderboard</Link>
				</div>
				<div className="option-box">
					<Link className="option" to={"/user_page/" + localStorage.getItem("id")}>Profile</Link>
				</div>
				<div className="option-box">
					<Link className="option" to={"/settings"}>Settings</Link>
				</div>
				<div className="option-box">
					<Link onClick={LogOut} className="option" to={"/login"}>Log out</Link>
				</div>
			</div>
		)
	}

	if (username === "") {
		axios.get('http://localhost:3660/users/' + localStorage.getItem("id"))
			.then(function (response) {
				setUsername(response.data.username);
				if (response.data.avatar) {
					axios.get('http://localhost:3660/file/' + response.data.avatar, {
						responseType: 'blob'
					})
						.then(function (response) {
							setAvatar(URL.createObjectURL(response.data));
						})
						.catch(function (error) { console.log(error); })
				}
			})
			.catch(function (error) {
				console.log(error);
			});
	}

	return (
		<div className="menu">
			<div className='menu-button' onClick={function () { setShowMenu(!showMenu) }}>
				<img id="avatar" className="avatar" src={avatar} alt="user avatar" />
				<p id="username" className="username">{username}</p>
				<Arrow />
			</div>
			<Options />
		</div>
	)
}