import Banner from "../Banner/Banner"
import axios from "axios";
import { useState, useEffect } from "react";

export default function TwoFAenable() {
	function QRcode() {
		const [QRcodePath, setQRcodePath] = useState<string>();
		useEffect(() => {
			axios.get("http://localhost:3660/auth/2fa/QRcode/" + localStorage.getItem("id"))
				.then(response => {
					setQRcodePath(response.data);
				})
				.catch(error => {
					console.log(error);
				})
		}, [])

		return <img src={QRcodePath} />
	}

	return (
		<>
			<Banner />
			<div className="page">
				<h1>Enable two factor authentication</h1>
				<QRcode />
			</div>
		</>
	)
}