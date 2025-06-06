import { useState } from "react";
import axios from 'axios';
import { Link } from "react-router-dom";

let userList: { id: string, username: string }[] = [];

export default function UserSearch() {
	const [searchValue, setSearchValue] = useState("");

	if (userList.length === 0) {
		axios.get('http://localhost:3660/users')
			.then(function (value) {
				userList = value.data;
			})
			.catch(function (error) {
				console.log(error);
			});
	}
	const onSearch = (e: React.ChangeEvent<HTMLInputElement>) => {
		setSearchValue(e.target.value);
	};

	function getUserDisplay(user: { id: string, username: string }) {
		return (
			<Link
				className="search-results-item"
				to={"/user_page/" + user.id}
				onClick={function (e) { setSearchValue("") }}
			>
				<div className="search-result-text">{user.username}</div>
			</Link>
		)
	}

	function getSearchResults(searchValue: string) {
		if (searchValue === "")
			return ("");
		return (
			<div className="search-results">
				{userList.filter(option => option.username.toLowerCase().includes(searchValue.toLowerCase()) && option.id !== localStorage.getItem("id")).map((option) => (
					getUserDisplay(option)
				))}
			</div>
		)
	}

	return (
		<div className="user-search">
			<input
				className="input-bar"
				placeholder="search..."
				onChange={onSearch}
				value={searchValue}
			/>
			{getSearchResults(searchValue)}
		</div>
	)
}
