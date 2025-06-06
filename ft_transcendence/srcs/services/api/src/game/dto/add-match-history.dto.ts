import { IsNotEmpty, IsNumber } from "class-validator";

export class AddGameDto {
	@IsNotEmpty()
	@IsNumber()
	winner_id: number;

	@IsNotEmpty()
	@IsNumber()
	loser_id: number;

	@IsNotEmpty()
	@IsNumber()
	winner_score: number;

	@IsNotEmpty()
	@IsNumber()
	loser_score: number
  }