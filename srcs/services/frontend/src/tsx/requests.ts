import axios from "axios";

export async function sendRequest(id: number) {
	await axios.post('http://localhost:3660/relations/' + localStorage.getItem("id") + "/" + id + "/send_request")
		.catch(function (error) { console.log(error) });
}

export async function acceptRequest(id: number) {
	await axios.patch('http://localhost:3660/relations/' + localStorage.getItem("id") + "/" + id + "/accept_request")
		.catch(function (error) { console.log(error) });
}

export async function removeRelation(id: number) {
	await axios.delete('http://localhost:3660/relations/' + localStorage.getItem("id") + "/" + id)
		.catch(function (error) { console.log(error) });
}

export async function block(id: number) {
	removeRelation(id);
	await axios.post('http://localhost:3660/relations/' + localStorage.getItem("id") + "/" + id + "/block")
		.catch(function (error) { console.log(error) });
}

export async function unblock(id: number) {
	await axios.delete('http://localhost:3660/relations/' + localStorage.getItem("id") + "/" + id + "/block")
		.catch(function (error) { console.log(error) });
}