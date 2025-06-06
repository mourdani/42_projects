import "../../css/Banner.css";
import * as React from 'react';
import { Menu } from "./Menu";
import UserSearch from "./UserSearch";
import { Navigate, useNavigate } from "react-router-dom";
import axios from "axios";
import { socket } from "../App";

export default function Banner() {
	const navigate = useNavigate();
	if (Object.is(localStorage.getItem("id"), null)) {
		return <Navigate to="/login" />
	}

	axios.interceptors.response.use(
		response => response,
		error => {
			if (error.response.status === 401) {
				localStorage.clear();
				navigate("/login")
			}
			return Promise.reject(error)
		}
	);

	socket.on("invite-accepted", (roomId: string, callback) => {
		navigate('/pong/' + roomId);
	})

	return (
		<div className="banner">
			<div className="banner-text">
				<p>pong</p>
			</div>
			<UserSearch />
			<Menu />
		</div>
	)
}
