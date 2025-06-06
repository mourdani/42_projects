import '../../css/pageContent/Settings.css';
import '../../css/pageContent/PageContent.css';
import { useEffect, useState } from "react";
import axios from 'axios';
import Banner from '../Banner/Banner';
import { useNavigate } from 'react-router-dom';


function UsernameForm() {
	const [newUsername, setNewUsername] = useState("");
	const [errorUsername, setErrorUsername] = useState("")

	function onChange(e: React.ChangeEvent<HTMLInputElement>) {
		setNewUsername(e.target.value);
	}

	function changeUsername(e: React.FormEvent<HTMLFormElement>) {
		e.preventDefault();

		axios.patch('http://localhost:3660/users/' + localStorage.getItem("id") + '/change_username', {
			newUsername: newUsername
		})
			.then(function (value) {
				if (value !== undefined) {
					const element = document.getElementById("username")
					if (element != null) {
						element.innerHTML = newUsername;
					}
					setErrorUsername(value.data);
				}
			})
			.catch(function (error) {
				if (error.response.status && error.response.status === 400) {
					console.log(error.response.data.message);
					setErrorUsername(error.response.data.message[0]);
				} else {
					setErrorUsername("Woops, something went wrong. Please try again later.")
				}
			})
	}
	return (
		<form className="form" onSubmit={changeUsername}>
			<label>New Username:</label>
			<input
				type="username"
				placeholder='new username...'
				value={newUsername}
				onChange={onChange}
				id="newUsername"
				className="text-input"
			/>
			<div className="error-message">{errorUsername}</div>
			<input
				type="submit"
				value="submit"
				className="button"
			/>
		</form>
	)
}

function AvatarForm() {
	const [newAvatar, setNewAvatar] = useState<File>();
	const [errorAvatar, setErrorAvatar] = useState("")

	function onChangeAvatar(e: React.ChangeEvent<HTMLInputElement>) {
		if (e.target.files) {
			setNewAvatar(e.target.files[0]);
		}
	}

	function changeAvatar(e: React.SyntheticEvent) {
		e.preventDefault();

		if (!newAvatar) {
			setErrorAvatar("");
			return;
		}
		let formData = new FormData();
		formData.append("avatar", newAvatar);
		axios.patch("http://localhost:3660/users/" + localStorage.getItem("id") + "/change_avatar", formData, {
			headers: {
				"Content-Type": "multipart/form-data",
			}
		})
			.then(function (response) {
				console.log(response);
				setErrorAvatar("Avatar changed successfully.");
			})
			.catch(function (error) {
				console.log(error);
				setErrorAvatar(error.response.data.message);
			})
	}
	return (
		<form className="form" onSubmit={changeAvatar}>
			<label>New Avatar:</label>
			<input
				type="file"
				id="newAvatar"
				className="image-input"
				onChange={onChangeAvatar}
			/>
			{newAvatar && (
				<img className="avatar-preview" src={URL.createObjectURL(newAvatar)} />
			)}
			<input
				type="submit"
				value="submit"
				className="button"
			/>
			<div className="error-message">{errorAvatar}</div>
		</form>
	)
}

function TwoFactorAuthentication() {
	const [twoFA, setTwoFA] = useState<boolean>();
	const navigate = useNavigate();

	useEffect(() => {
		axios.get("http://localhost:3660/auth/2fa/enabled/" + localStorage.getItem("id"))
			.then(response => {
				setTwoFA(response.data);
			})
			.catch(error => {
				console.log(error);
			})
	}, [])

	function disableTwoFA() {
		axios.patch("http://localhost:3660/auth/2fa/disable/" + localStorage.getItem("id"))
			.then(() => setTwoFA(false))
			.catch((error) => console.log(error));
	}

	if (twoFA === undefined) {
		return <></>;
	} else if (twoFA) {
		return <button className='twofa-button' onClick={disableTwoFA}>disable 2FA</button>
	} else {
		return (
			<div>
				<button className='twofa-button' onClick={() => navigate("/2fa/enable")}>enable 2FA</button>
			</div>
		)
	}
}

export default function Settings() {
	return (
		<>
			<Banner />
			<div className="page">
				<h1>Settings</h1>
				<UsernameForm />
				<AvatarForm />
				<TwoFactorAuthentication />
			</div>
		</>
	)
}
