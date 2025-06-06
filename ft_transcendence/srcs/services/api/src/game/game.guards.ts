import {
	CanActivate,
	ExecutionContext,
	Injectable,
	ForbiddenException,
} from '@nestjs/common';
import { JwtService } from '@nestjs/jwt';
import { Request } from 'express';

//guard used to check if person making request is loser
@Injectable()
export class GameGuard implements CanActivate {
	constructor(private jwtService: JwtService) { }

	async canActivate(context: ExecutionContext): Promise<boolean> {
		const request = context.switchToHttp().getRequest();
		const token = this.extractTokenFromHeader(request);
		const id = request.body.loser_id;

		console.log(request.body);
		if (!token) {
			throw new ForbiddenException();
		}
		if (id !== undefined && this.jwtService.verify(token).id !== +id) {
			throw new ForbiddenException();
		}

		return true;
	}


	private extractTokenFromHeader(request: Request): string | undefined {
		const [type, token] = request.headers.authorization?.split(' ') ?? [];
		return type === 'Bearer' ? token : undefined;
	}
}