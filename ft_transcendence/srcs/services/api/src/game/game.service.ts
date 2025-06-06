import { Injectable } from '@nestjs/common';
import { achievement } from '@prisma/client';
import { PrismaService } from 'src/prisma/prisma.service';

@Injectable()
export class GameService {
	constructor(private prisma: PrismaService) { }

	async add_match(message: {
		winner_id: number,
		loser_id: number,
		winner_score: number,
		loser_score: number
	}) {
		try {
			await this.prisma.match_history.create({
				data: message,
			});

		} catch (error) { console.log(error) }

		//updating points
		try {
			await this.prisma.user.update({
				where: { id: message.winner_id },
				data: { exp: { increment: (message.winner_score - message.loser_score) * 10 } }
			})
		} catch (error) { console.log(error) }
		try {
			await this.prisma.user.update({
				where: { id: message.loser_id },
				data: { exp: { decrement: (message.winner_score - message.loser_score) * 5 } }
			});
			const user = await this.prisma.user.findUnique({
				where: { id: message.loser_id }
			});
			if (user.exp < 0) {
				await this.prisma.user.update({
					where: { id: message.loser_id },
					data: { exp: 0 }
				})
			}
		} catch (error) { console.log(error) }
	}

	async checkAchievements(id: number, socketId: string, io: any) {
		const newAchievements: Array<achievement> = [];

		const wins = await this.prisma.match_history.findMany({
			where: {
				winner_id: id,
			}
		})
		const losses = await this.prisma.match_history.findMany({
			where: {
				loser_id: id,
			}
		})
		const achievements = await this.prisma.achievement.findMany({
			where: {
				OR: [{ win_requirement: wins.length },
				{ lose_requirement: losses.length },
				{ play_requirement: wins.length + losses.length }]
			},
		});
		for (let achievement of achievements) {
			try {
				var earned = await this.prisma.earned_achievement.findMany({
					where: {
						achievement_id: achievement.achievement_id,
						user_id: id
					}
				})
				if (earned.length === 0) {
					await this.prisma.earned_achievement.create({
						data: {
							achievement_id: achievement.achievement_id,
							user_id: id
						}
					})
					newAchievements.push(achievement);
				}
			} catch (error) { console.log(error) }
		}
		if (newAchievements.length !== 0) {
			io.to(socketId).emit('earn-achievements', newAchievements);
		}
	}

	async getHistory(id: number) {
		var history = await this.prisma.match_history.findMany({
			include: {
				winner_user: true,
				loser_user: true
			},
			where: {
				OR: [{
					winner_id: +id
				},
				{
					loser_id: +id
				}]
			},
			orderBy: {
				time: 'desc'
			}
		});
		return history;
	}

	async getAchievements(id: number) {
		var achievements = await this.prisma.earned_achievement.findMany({
			include: {
				achievement: true,
			},
			where: {
				user_id: +id
			}
		});
		return achievements;
	}
}
