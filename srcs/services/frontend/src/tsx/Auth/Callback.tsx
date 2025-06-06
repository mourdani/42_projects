import { useSearchParams } from "react-router-dom";
import axios from "axios";
import { useNavigate } from "react-router-dom";
import { Navigate } from "react-router-dom";
import { useCookies } from "react-cookie";
import ReactCodeInput from "react-code-input";
import { useEffect, useState, useRef } from "react";

export default function Callback() {
	const [queryParameters] = useSearchParams();
	const navigate = useNavigate();
	const [cookies, setCookie] = useCookies(['token']);
	const idRef = useRef<string>("0");
	const [twoFA, setTwoFA] = useState(false);
	const [error, setError] = useState("");
	const [navigateTo, setNavigateTo] = useState("");

	if (!Object.is(localStorage.getItem("id"), null)) {
		navigate("/pong");
	}

	useEffect(() => {
		axios.post("http://localhost:3660/auth/", { code: queryParameters.get("code") })
			.then(res => {
				if (res.data.twoFA) {
					idRef.current = res.data.id;
					setTwoFA(true);
				} else {
					setCookie("token", res.data.token, { maxAge: 60 });
					axios.defaults.headers.common["Authorization"] = `Bearer ${res.data.token}`;
					axios.get("http://localhost:3660/users/" + res.data.id)
						.then(res => { localStorage.setItem("id", res.data.id); setNavigateTo("/pong") })
						.catch(err => { setNavigateTo("/register/" + res.data.id) })
				}
			})
			.catch(err => {
				console.log(err)
				navigate("/login");
			})
	}, [])

	function TwoFactorAuthentication() {
		const [pinCode, setPinCode] = useState<string>();

		function handlePinChange(code: string) {
			setPinCode(code);
			if (code?.length === 6) {
				axios.post("http://localhost:3660/auth/2fa", { id: idRef.current, token: code })
					.then(res => {
						if (res.data.token) {
							setCookie("token", res.data.token, { maxAge: 60 });
							axios.defaults.headers.common["Authorization"] = `Bearer ${res.data.token}`;
							localStorage.setItem("id", idRef.current);
							setTwoFA(false);
						} else {
							setError("Invalid code. Please try again.");
							setPinCode("");
							console.log("bad code");
						}
					})
					.catch(err => {
						console.log(err);
						setPinCode("");
						setError("Woops, something went wrong. Please try again.");
					})
			}
		}
		return (
			<div className="page">
				<h1>Enter 2FA code</h1>
				<ReactCodeInput
					inputMode="numeric"
					name="pin"
					type="password"
					fields={6}
					onChange={handlePinChange}
					value={pinCode}
				/>
				<div>{error}</div>
			</div>
		);
	}

	if (!Object.is(localStorage.getItem("id"), null)) {
		return (<Navigate to="/pong" />);
	}


	if (twoFA) {
		return <TwoFactorAuthentication />
	} else if (navigateTo !== "") {
		return (<Navigate to={navigateTo} />);
	} else {
		return <></>
	}
}