import { Injectable } from '@nestjs/common';
import { UsersService } from '../users/users.service';
import { JwtService } from '@nestjs/jwt';
import { PrismaService } from 'src/prisma/prisma.service';
import { NotFoundException } from '@nestjs/common';
import { Prisma } from '@prisma/client';

@Injectable()
export class AuthService {
	constructor(
		private usersService: UsersService,
		private jwtService: JwtService,
		private prisma: PrismaService
	) { }

	async signIn(message: { code: string }) {
		if (message.code.length === 1) { //TODO remove before turning in
			return ({
				token: await this.jwtService.signAsync({ id: +message.code }),
				id: +message.code
			});
		}
		const userID = await this.usersService.login(message.code);
		const twoFA = await this.prisma.twoFASecret.findUnique({ where: { id: userID.id } });
		console.log(twoFA);
		return ({
			token: await this.jwtService.signAsync({ id: userID.id, twoFA: !!twoFA }),
			id: userID.id,
			twoFA: !!twoFA
		});
	}

	async twoFA(id: number, token: string) {
		const speakeasy = require("speakeasy");
		const secret = (await this.prisma.twoFASecret.findUnique({
			where:
			{
				id: +id
			}
		})).twoFASecret as Prisma.JsonObject;
		if (!secret || secret === undefined) {
			return { token: await this.jwtService.signAsync({ id: id, twoFA: false }) }
		}
		var tokenValidates: boolean = speakeasy.totp.verify({
			secret: secret.base32,
			encoding: 'base32',
			token: token,
		});
		if (tokenValidates) {
			return { token: await this.jwtService.signAsync({ id: id, twoFA: false }) }
		} else {
			return { token: null }
		}
	}

	async twoFAenabled(id: number) {
		const user = await this.prisma.twoFASecret.findUnique({ where: { id: +id } });
		return !!user;
	}

	async getTwoFAQRcode(id: number) {
		const speakeasy = require('speakeasy');
		const qrcode = require('qrcode');

		var otpauthURL: string;
		const twoFA = await this.prisma.twoFASecret.findUnique({ where: { id: +id } });
		if (twoFA !== null) {
			const secret = twoFA.twoFASecret as Prisma.JsonObject;
			otpauthURL = secret.otpauth_url as string;
		} else {
			const secret = speakeasy.generateSecret({
				name: "ft_transcendance"
			});
			await this.prisma.twoFASecret.create({
				data: {
					id: +id,
					twoFASecret: secret
				}
			})
			otpauthURL = secret.otpauth_url;
		}
		return qrcode.toDataURL(otpauthURL);
	}

	async deleteTwoFA(id: number) {
		try {
			await this.prisma.twoFASecret.delete({
				where: {
					id: +id
				}
			})
		} catch (error) {
			console.log(error);
			throw new NotFoundException(`User with id: ${id} does not have 2FA.`);
		}
	}
}