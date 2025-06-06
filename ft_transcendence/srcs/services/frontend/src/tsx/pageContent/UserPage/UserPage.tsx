import Banner from "../../Banner/Banner";
import { useParams } from "react-router-dom";
import "../../../css/pageContent/UserPage/UserPage.css";
import "../../../css/pageContent/PageContent.css";
import { useEffect, useState } from "react";
import axios from "axios";
import { Dots } from "../../svgIcons";
import PrivateInfo from "./PrivateInfo";
import UserDisplay from "../components/UserDisplay";
import {
	acceptRequest,
	block,
	unblock,
	removeRelation,
	sendRequest,
} from "../../requests";

type status = {
	blocked: boolean;
	blocking: boolean;
	pending: boolean;
	request: boolean;
	friends: boolean;
};

export default function UserPage() {
	let { id } = useParams();
	const [status, setStatus] = useState<status>();

	function getStatus() {
		axios
			.get("http://localhost:3660/relations/" + localStorage.getItem("id") + "/" + id)
			.then(function (response) {
				setStatus(response.data);
			})
			.catch(function (error) {
				console.log(error);
			});
	}

	useEffect(() => {
		getStatus();
	}, []);

	function UserInfo() {

		function PublicInfo() {
			const [showMenu, setShowMenu] = useState(false);

			function update() {
				getStatus();
				if (showMenu) {
					setShowMenu(false);
				}
			}

			function Menu() {
				if (!status) {
					return <></>;
				}
				if (status.blocking) {
					return (
						<div className="up-menu-list">
							<div
								onClick={function () {
									unblock(+id!).then(function () {
										update();
									});
								}}
								className="up-menu-list-item"
							>
								Unblock
							</div>
						</div>
					);
				}
				if (status.blocked) {
					return (
						<div className=" up-menu-list">
							<div
								onClick={function () {
									block(+id!).then(function () {
										update();
									});
								}}
								className="up-menu-list-item"
							>
								Block
							</div>
						</div>
					);
				}
				if (status.friends) {
					return (
						<div className=" up-menu-list">
							<div className="up-menu-list-item">Message</div>
							<div
								onClick={function () {
									removeRelation(+id!).then(function () {
										update();
									});
								}}
								className="up-menu-list-item"
							>
								Unfriend
							</div>
							<div
								onClick={function () {
									block(+id!).then(function () {
										update();
									});
								}}
								className="up-menu-list-item"
							>
								Block
							</div>
						</div>
					);
				}
				if (status.pending) {
					return (
						<div className=" up-menu-list">
							<div
								onClick={function () {
									removeRelation(+id!).then(function () {
										update();
									});
								}}
								className="up-menu-list-item"
							>
								Unsend request
							</div>
							<div
								onClick={function () {
									block(+id!).then(function () {
										update();
									});
								}}
								className="up-menu-list-item"
							>
								Block
							</div>
						</div>
					);
				}
				if (status.request) {
					return (
						<div className=" up-menu-list">
							<div
								onClick={function () {
									acceptRequest(+id!).then(function () {
										update();
									});
								}}
								className="up-menu-list-item"
							>
								Accept request
							</div>
							<div
								onClick={function () {
									removeRelation(+id!).then(function () {
										update();
									});
								}}
								className="up-menu-list-item"
							>
								Deny request
							</div>
							<div
								onClick={function () {
									block(+id!).then(function () {
										update();
									});
								}}
								className="up-menu-list-item"
							>
								Block
							</div>
						</div>
					);
				}
				return (
					<div className=" up-menu-list">
						<div
							onClick={function () {
								sendRequest(+id!).then(function () {
									update();
								});
							}}
							className="up-menu-list-item"
						>
							Add user
						</div>
						<div
							onClick={function () {
								block(+id!).then(function () {
									update();
								});
							}}
							className="up-menu-list-item"
						>
							Block
						</div>
					</div>
				);
			}

			return (
				<div className="up-user-display">
					<UserDisplay id={id!} />
					{id === localStorage.getItem("id") ? (
						<></>
					) : (
						<div className="up-menu">
							<div onClick={function () { setShowMenu(!showMenu) }}>
								<Dots className="icon" />
							</div>
							{showMenu ? <Menu /> : <></>}
						</div>
					)}
				</div>
			);
		}

		return (
			<div className="page">
				<PublicInfo />
				{<PrivateInfo isFriend={status?.friends} id={id!} />}
			</div>
		);
	}

	return (
		<>
			<Banner />
			<UserInfo />
		</>
	);
}

// export function getId() {


// export user.username
export function getUsername(id: number) {
	axios
		.get("http://localhost:3660/users/" + id)
		.then(function (response) {
			return response.data.username;
		})
		.catch(function (error) {
			console.log(error);
			return "";
		});
	return "";
}
