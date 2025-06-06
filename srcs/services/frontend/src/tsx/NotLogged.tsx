import Login from './Auth/Login';
import { useState } from "react";
import "../css/Loging.css"
import { Link } from 'react-router-dom';

export default function NotLogged() {
	return (
		<div className='login-buttons'>
			<div>
				<Link to={'/login'}>login</Link>
			</div>
		</div>
	)
}