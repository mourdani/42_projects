import { Controller, Post, Body, HttpCode, HttpStatus, Get, Param, UseGuards, Patch } from '@nestjs/common';
import { AuthService } from './auth.service';
import { UserGuard } from 'src/users/users.guards';
import { AuthGuard } from './auth.guards';

@Controller("auth")
export class AuthController {
	constructor(private authService: AuthService) { }

	@HttpCode(HttpStatus.OK)
	@Post()
	async auth(@Body() message: { code: string }) {
		console.log("/auth");
		var res = await this.authService.signIn(message);;
		return (res);
	}

	@Post('/2fa')
	async twofa(@Body() message: { id: number, token: string }) {
		console.log('/2fa');
		return await this.authService.twoFA(message.id, message.token);
	}

	@Get('/2fa/enabled/:id')
	@UseGuards(AuthGuard, UserGuard)
	async enabled(@Param('id') id: number) {
		console.log("/2fa/enabled/" + id);
		return this.authService.twoFAenabled(id);
	}

	@Get('/2fa/QRcode/:id')
	@UseGuards(AuthGuard, UserGuard)
	async getQR(@Param('id') id: number) {
		console.log("/2fa/QRcode/" + id);
		return this.authService.getTwoFAQRcode(id);
	}

	@Patch('/2fa/disable/:id')
	@UseGuards(AuthGuard, UserGuard)
	async deletetwoFA(@Param('id') id: number) {
		console.log("/2fa/disable/" + id);
		return this.authService.deleteTwoFA(id);
	}
}
