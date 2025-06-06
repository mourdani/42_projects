import {
	CanActivate,
	ExecutionContext,
	Injectable,
	ForbiddenException,
} from '@nestjs/common';
import { JwtService } from '@nestjs/jwt';
import { Request } from 'express';
import { PrismaService } from 'src/prisma/prisma.service';

@Injectable()
export class BlockGuard implements CanActivate {
	constructor(private jwtService: JwtService, private prisma: PrismaService) { }

	async canActivate(context: ExecutionContext): Promise<boolean> {
		const request = context.switchToHttp().getRequest();
		const token = this.extractTokenFromHeader(request);
		const id = request.params.id;

		if (!token) {
			throw new ForbiddenException();
		}
		if (!id) {
			return true;
		}
		const block = await this.prisma.block.findFirst({
			where: {
				blocked_id: this.jwtService.verify(token).id,
				blocking_id: +id
			}
		})
		console.log(block);
		if (block !== null) {
			throw new ForbiddenException(`You are blocked by user ${id}`);
		}

		return true;
	}


	private extractTokenFromHeader(request: Request): string | undefined {
		const [type, token] = request.headers.authorization?.split(' ') ?? [];
		return type === 'Bearer' ? token : undefined;
	}
}

@Injectable()
export class RecieverBlockGuard implements CanActivate {
	constructor(private jwtService: JwtService, private prisma: PrismaService) { }

	async canActivate(context: ExecutionContext): Promise<boolean> {
		const request = context.switchToHttp().getRequest();
		const token = this.extractTokenFromHeader(request);
		const id = request.params.reciever;

		if (!token) {
			throw new ForbiddenException();
		}
		const block = await this.prisma.block.findFirst({
			where: {
				blocked_id: this.jwtService.verify(token).id,
				blocking_id: +id
			}
		})
		if (block !== null) {
			throw new ForbiddenException(`You are blocked by user ${id}`);
		}

		return true;
	}


	private extractTokenFromHeader(request: Request): string | undefined {
		const [type, token] = request.headers.authorization?.split(' ') ?? [];
		return type === 'Bearer' ? token : undefined;
	}
}