import { Injectable } from '@nestjs/common';
import { CreateBlockDto } from './dto/create-block.dto';
import { UpdateBlockDto } from './dto/update-block.dto';
import { PrismaService } from '../prisma/prisma.service';


@Injectable()
export class BlocksService {

	constructor(private prisma: PrismaService) { }

	create(createBlockDto: CreateBlockDto) {
		return this.prisma.block.create({
			data: {
				blocked_id: createBlockDto.blockedId,
				blocking_id: createBlockDto.blockingId,
			},
		});
	}

	findBlockedUsersByUserId(userId: number) {
		return this.prisma.block.findMany({
			where: {
				OR: [
					{ blocking_id: userId },
					{ blocked_id: userId },
				],
			},
		});
	}

	delete(blockingId: number, blockedId: number) {
		return this.prisma.block.delete({ where: { blocking_id_blocked_id: { blocking_id: blockingId, blocked_id: blockedId } } });
	}

}
