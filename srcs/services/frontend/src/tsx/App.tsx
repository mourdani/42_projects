import "../css/App.css";
import "../css/pageContent/PageContent.css";
import { createBrowserRouter, RouterProvider, Navigate } from "react-router-dom";
import Login from './Auth/Login';
import Pong from './pageContent/Pong';
import Chat from "./pageContent/Chat";
import Leaderboard from "./pageContent/Leaderboard";
import Settings from "./pageContent/Settings";
import Callback from "./Auth/Callback";
import UserPage from "./pageContent/UserPage/UserPage";
import axios from "axios";
import { useCookies } from "react-cookie";
import Register from "./Register";
import TwoFAenable from "./pageContent/TwoFAEnable";
import { AchievementPopUp } from "./pageContent/Game/AchievementPopUp";
import { io } from "socket.io-client";
import { useEffect } from "react";
import { InvitePopup } from "./pageContent/components/InvitePopup";

export const socket = io('localhost:3660'); // initialize websocket connection

export function App() {
	function Redirection() {
		if (Object.is(localStorage.getItem("id"), null)) {
			return <Navigate to="/login" />
		} else {
			return <Navigate to="/pong" />
		}
	}

	useEffect(() => {
		let id = localStorage.getItem("id");
		if (id !== undefined && id !== null) {
			socket.emit("log-in", id);
		}
		return () => {
			let id = localStorage.getItem("id");
			if (id !== undefined && id !== null) {
				socket.emit("log-out", id);
			}
		};
	}, [])

	const [cookies, setCookie, removeCookie] = useCookies(['token']);

	axios.defaults.headers.common["Authorization"] = `Bearer ${cookies.token}`;

	const router = createBrowserRouter([
		{
			path: "/",
			element: <Redirection />,
		},
		{
			path: "/login",
			element: <Login />
		},
		{
			path: "/pong",
			element: <Pong />
		},
		{
			path: "/pong/:roomId",
			element: <Pong />
		},
		{
			path: "/Chat",
			element: <Chat />
		},
		{
			path: "/Leaderboard",
			element: <Leaderboard />
		},
		{
			path: "/Settings",
			element: <Settings />
		},
		{
			path: "/Callback",
			element: <Callback />
		},
		{
			path: "/user_page/:id",
			element: <UserPage />
		},
		{
			path: "/register/:id",
			element: <Register />
		},
		{
			path: "/2fa/enable",
			element: <TwoFAenable />
		}
	]);

	return (
		<div className="app">
			<script src="/socket.io/socket.io.js"></script>
			<AchievementPopUp />
			<InvitePopup />
			<RouterProvider router={router} />
		</div>

	)
}
