import { Controller, Get, Param, UseGuards, Post, Delete, Patch } from '@nestjs/common';
import { RelationsService } from './relations.service';
import { AuthGuard } from 'src/auth/auth.guards';
import { BlockGuard, RecieverBlockGuard } from './relations.guards';
import { UserGuard } from 'src/users/users.guards';

@Controller('relations')
export class RelationsController {
	constructor(private readonly relationsService: RelationsService) { }

	@UseGuards(AuthGuard, BlockGuard, RecieverBlockGuard)
	@Get('/:id/:reciever')
	async relation(@Param("id") id: number, @Param("reciever") related: number) {
		console.log("/relation/");
		return await this.relationsService.getRelation(id, related);
	}

	@UseGuards(AuthGuard, UserGuard)
	@Get("/:id/:reciever/blocked")
	async blocked(@Param("id") id: number, @Param("reciever") related: number) {
		console.log("/relation/blocked/");
		return await this.relationsService.getBlocked(id, related);
	}

	@UseGuards(AuthGuard, RecieverBlockGuard, UserGuard)
	@Post('/:id/:reciever/send_request')
	async sendRequest(@Param("id") sender: number, @Param("reciever") reciever: number) {
		console.log("/relation/send_request")
		await this.relationsService.sendRequest(sender, reciever);
	}

	@UseGuards(AuthGuard, UserGuard, RecieverBlockGuard)
	@Patch('/:id/:reciever/accept_request')
	async acceptRequest(@Param("id") user1: number, @Param("reciever") user2: number) {
		console.log("/relation/accept_request")
		await this.relationsService.acceptRequest(user1, user2);
	}

	@UseGuards(AuthGuard, UserGuard)
	@Post('/:id/:reciever/block')
	async block(@Param("id") blocker: number, @Param("reciever") blocked: number) {
		console.log("/relation/block")
		await this.relationsService.block(blocker, blocked);
	}

	@UseGuards(AuthGuard, UserGuard)
	@Delete('/:id/:reciever/block')
	async unblock(@Param("id") blocker: number, @Param("reciever") blocked: number) {
		console.log("/relation/block")
		await this.relationsService.unblock(blocker, blocked);
	}

	@UseGuards(AuthGuard, UserGuard)
	@Delete('/:id/:reciever')
	async deleteRelation(@Param("id") user1: number, @Param("reciever") user2: number) {
		console.log("/relation/remove_relation")
		await this.relationsService.deleteRelation(user1, user2);
	}
}


