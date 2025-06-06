import "../../css/Login.css"
import { useNavigate, Navigate } from "react-router-dom";
import axios from 'axios';
import { useCookies } from "react-cookie";
import { socket } from "../App";

export default function Login() {
	const [cookies, setCookie, removeCookie] = useCookies(['token']);
	const navigate = useNavigate();

	if (localStorage.getItem("id")) {
		return <Navigate to="/pong" />
	}

	function login() {
		window.location.href = "https://api.intra.42.fr/oauth/authorize?client_id=u-s4t2ud-bca5b5ca59fdfab1c4827aa0f8698120d89e4d34d19e01b6102dc96f525087cd&redirect_uri=http%3A%2F%2Fanm-pong.42.fr%3A80%2Fcallback&response_type=code"
	}

	function login_admin(id: string) {
		axios.post("http://localhost:3660/auth/", { code: id })
			.then(res => {
				console.log(res.data);
				localStorage.setItem("id", id);
				setCookie("token", res.data.token, { maxAge: 3600 });
				axios.defaults.headers.common["Authorization"] = `Bearer ${res.data.token}`;
				socket.emit("log-in", id)
				navigate("/pong");
			})
			.catch(err => { console.log(err) })
	}

	return (
		<div className="login-buttons">
			<div className="login-button" onClick={login}>
				<div className="login-text">
					Login
				</div>
			</div>
			<button onClick={function () { login_admin("1") }}>Archi</button>
			<button onClick={function () { login_admin("3") }}>Meziane</button>
			<button onClick={function () { login_admin("2") }}>Noam</button>
		</div>
	)
}
