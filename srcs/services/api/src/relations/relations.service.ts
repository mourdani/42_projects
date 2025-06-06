import { BadRequestException, Injectable } from '@nestjs/common';
import { PrismaService } from 'src/prisma/prisma.service';
import { relation_status } from '@prisma/client';

@Injectable()
export class RelationsService {
	constructor(private prisma: PrismaService) { }

	async getRelation(requesting: number, requested: number) {
		var relation = {
			blocked: false,
			blocking: false,
			pending: false,
			request: false,
			friends: false
		}
		var relation_db = await this.prisma.friendship.findMany({
			where: {
				relating_id: +requesting,
				related_id: +requested
			}
		});
		if (relation_db.length !== 0) {
			if (relation_db[0].relation.valueOf() === 'F') {
				relation.friends = true;
				return relation;
			}
			if (relation_db[0].relation.valueOf() === 'S') {
				relation.pending = true;
				return relation;
			}
			if (relation_db[0].relation.valueOf() === 'R') {
				relation.request = true;
				return relation;
			}
		}
		var block = await this.prisma.block.findMany({
			where: {
				blocking_id: +requested,
				blocked_id: +requesting
			}
		});
		if (block.length !== 0) {
			relation.blocked = true;
		}
		var block = await this.prisma.block.findMany({
			where: {
				blocking_id: +requesting,
				blocked_id: +requested
			}
		});
		if (block.length !== 0) {
			relation.blocking = true;
		}
		return (relation);
	}

	async getBlocked(requesting: number, requested: number) {
		let relation: { blocked: boolean, blocking: boolean } = { blocked: false, blocking: false };

		var block = await this.prisma.block.findMany({
			where: {
				blocking_id: +requested,
				blocked_id: +requesting
			}
		});
		if (block.length !== 0) {
			relation.blocked = true;
		}
		var block = await this.prisma.block.findMany({
			where: {
				blocking_id: +requesting,
				blocked_id: +requested
			}
		});
		if (block.length !== 0) {
			relation.blocking = true;
		}
		return (relation);
	}

	async sendRequest(sender: number, reciever: number) {
		try {
			await this.prisma.friendship.create({
				data: {
					relating_id: +sender,
					related_id: +reciever,
					relation: relation_status.S
				}
			});
			await this.prisma.friendship.create({
				data: {
					relating_id: +reciever,
					related_id: +sender,
					relation: relation_status.R
				}
			});
		} catch (error: any) {
			console.log(error)
		}
	}

	async acceptRequest(user1: number, user2: number) {
		const count = await this.prisma.friendship.updateMany({
			where: {
				OR: [{
					relating_id: +user1,
					related_id: +user2,
					relation: relation_status.R
				},
				{
					relating_id: +user2,
					related_id: +user1,
					relation: relation_status.S
				}]
			},
			data: {
				relation: relation_status.F
			}
		});
		if (count.count === 0) {
			throw new BadRequestException(`There was no pending request between ${user1} and ${user2}`)
		}
	}

	async block(blocker: number, blocked: number) {
		try {
			await this.prisma.block.create({
				data: {
					blocking_id: +blocker,
					blocked_id: +blocked,
				}
			});
		} catch (e: any) {
			throw new BadRequestException(`User ${blocked} does not exist or is already blocked`)
		}
		try {
			await this.deleteRelation(blocker, blocked);
		} catch (e) { }
	}

	async unblock(blocker: number, blocked: number) {
		try {
			await this.prisma.block.deleteMany({
				where: {
					blocking_id: +blocker,
					blocked_id: +blocked,
				}
			});
		} catch (e: any) {
			console.log(e);
		}
	}

	async deleteRelation(user1: number, user2: number) {
		const count = await this.prisma.friendship.deleteMany({
			where: {
				OR: [{
					relating_id: +user1,
					related_id: +user2
				},
				{
					relating_id: +user2,
					related_id: +user1
				}]
			},
		})
		if (count.count === 0) {
			throw new BadRequestException(`Relation between ${user1} and ${user2} doesn't exist`)
		}
	}
}
