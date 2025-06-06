import { useState } from "react";
import { socket } from "../../App";

export function ActivityStatus(props: { width: number, id: string }) {
	const [color, setColor] = useState("#000000");

	socket.emit("user-status", props.id, (status: number) => {
		if (status === 0) { //logged out
			setColor("#2e2e2e");
		} else if (status === 1) { //logged in
			setColor("#0f910d");
		} else { //in game
			setColor("#d4c417");
		}
	})

	socket.on('log-out', (id: string) => {
		if (id === props.id) {
			setColor("#2e2e2e")
		}
	})

	socket.on('log-in', (id: string) => {
		if (id === props.id) {
			setColor("#0f910d")
		}
	})

	socket.on('in-game', (id: string) => {
		if (id === props.id) {
			setColor("#d4c417")
		}
	})
	return (
		<svg
			style={{ width: props.width, color: color }}
			viewBox="0 0 100 100"
			fill={color}
		>
			<circle cx="50" cy="50" r="50" />
		</svg>
	)
}