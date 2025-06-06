import "../../../css/pageContent/component/ProgressBar.css"

export default function ProgressBar(props: {exp: number, className: string}) {
	return (
		<div className={props.className}>
			<div>Lvl. {Math.trunc(props.exp / 100) + 1}</div>
			<div className="progress-bar">
				<div className="full-bar">
					<div className="filled-bar" style={{ 'width': `${props.exp - Math.trunc(props.exp / 100) * 100}%` }}></div>
				</div>
			</div>
		</div>
	);
}