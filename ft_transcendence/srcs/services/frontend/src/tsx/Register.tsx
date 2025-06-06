import { useRef, useState } from "react";
import axios from "axios";
import { useNavigate, useParams } from "react-router-dom";
import "../css/Form.css"
import "../css/pageContent/Settings.css"
import { Cross } from "./svgIcons";

export default function Register() {
	const [username, setUsername] = useState("");
	const [avatar, setAvatar] = useState<File>();
	const avatarRef = useRef<HTMLInputElement>(null)
	const [errorUsername, setErrorUsername] = useState("")
	const [errorAvatar, setErrorAvatar] = useState("")
	let { id } = useParams();
	const navigate = useNavigate();

	function onChange(e: React.ChangeEvent<HTMLInputElement>) {
		setUsername(e.target.value);
	}

	function createUser(e: React.FormEvent<HTMLFormElement>) {
		e.preventDefault();

		axios.post('http://localhost:3660/users/' + id, {
			id: +id!,
			username: username,
		})
			.then(res => {
				if (!avatar) {
					setErrorAvatar("");
					localStorage.setItem("id", id!);
					navigate("/pong");
				}
				let formData = new FormData();
				formData.append("avatar", avatar!);
				axios.patch("http://localhost:3660/users/" + id + "/change_avatar", formData, {
					headers: {
						"Content-Type": "multipart/form-data",
					}
				})
					.then(function (response) {
						console.log(response);
						localStorage.setItem("id", id!);
						navigate("/pong");
					})
					.catch(error => {
						setErrorUsername(error.response.data.message[0]);
					})
			})
	}

	function onChangeAvatar(e: React.ChangeEvent<HTMLInputElement>) {
		if (e.target.files) {
			setAvatar(e.target.files[0]);
		}
	}

	return (
		<div className="page">
			<h1>Register</h1>
			<form className="register-form" onSubmit={createUser}>
				<label>Username:</label>
				<input
					type="username"
					placeholder='Username...'
					value={username}
					onChange={onChange}
					id="username"
					className="text-input"
				/>
				<div className="error-message">{errorUsername}</div>
				<label>Avatar:</label>
				<div className="avatar-input">
					<input
						type="file"
						id="avatar"
						ref={avatarRef}
						className="image-input"
						onChange={onChangeAvatar}
					/>
					<div
						onClick={function (e) { if (avatarRef.current) { avatarRef.current.value = "" } }}
						className="file-cross"
					>
						<Cross className="file-cross" color="#b70c0c" />
					</div>
					<div className="error-message">{errorUsername}</div>
				</div>
				<input
					type="submit"
					value="submit"
					className="button"
				/>
			</form>
			<form onSubmit={function (e) { localStorage.clear(); navigate("/login"); }}>
				<input
					type="submit"
					value="cancel"
					className="button"
				/>
			</form>
		</div>
	)
}
