import { Controller, Get, Param, UseGuards } from '@nestjs/common';
import { AuthGuard } from 'src/auth/auth.guards';
import { GameService } from './game.service';
import { BlockGuard } from 'src/relations/relations.guards';

@Controller('game')
export class GameController {
	constructor(private readonly gameService: GameService) { }

	@UseGuards(AuthGuard, BlockGuard)
	@Get('/history/:id')
	async getHistory(@Param("id") id: number) {
		console.log("/game/histoy");
		return await this.gameService.getHistory(id);
	}

	@UseGuards(AuthGuard, BlockGuard)
	@Get('/achievements/:id')
	async getAchievements(@Param("id") id: number) {
		console.log("/game/achievements");
		return await this.gameService.getAchievements(id);
	}
}


