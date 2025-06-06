import {
	CanActivate,
	ExecutionContext,
	Injectable,
	ForbiddenException,
} from '@nestjs/common';
import { JwtService } from '@nestjs/jwt';
import { Request } from 'express';

//guard used to check if user making the request is user affected by request
@Injectable()
export class UserGuard implements CanActivate {
	constructor(private jwtService: JwtService) { }

	async canActivate(context: ExecutionContext): Promise<boolean> {
		const request = context.switchToHttp().getRequest();
		const token = this.extractTokenFromHeader(request);
		const id = request.params.id;

		if (!token) {
			throw new ForbiddenException("No token");
		}
		console.log("token id", this.jwtService.verify(token).id);
		if (id !== undefined && this.jwtService.verify(token).id !== +id) {
			throw new ForbiddenException("wrong user");
		}

		return true;
	}
//eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6MSwiaWF0IjoxNjkyMzgxMDM1LCJleHAiOjE2OTIzODgyMzV9.6ShZK9f49FkbjPY6jKTbLJ8IOMIUyfcfIPaLdiuLfCU
//eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6MTA2NjIzLCJ0d29GQSI6ZmFsc2UsImlhdCI6MTY5MjM4MjA4OCwiZXhwIjoxNjkyMzg5Mjg4fQ.14Y4m06qIZ-WqejA-mAb66YWNjD_aeNtbxPcKbEjW5Q
	private extractTokenFromHeader(request: Request): string | undefined {
		const [type, token] = request.headers.authorization?.split(' ') ?? [];
		return type === 'Bearer' ? token : undefined;
	}
}