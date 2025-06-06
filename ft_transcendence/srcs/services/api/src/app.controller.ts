import { Controller, Get, UseGuards, Param, Res } from '@nestjs/common';
import { AppService } from './app.service';
import { AuthGuard } from './auth/auth.guards';

export class newUsername {
	id: number;
	username: string
}

@Controller()
export class AppController {
	constructor(private readonly appService: AppService) {}

	@Get()
	getHello(): string {
		return this.appService.getHello();
	}

	@Get("/file/:filename")
	@UseGuards(AuthGuard)
	async getFile(@Param('filename') filename: string) {
		return this.appService.getFile(filename);
	}
}
