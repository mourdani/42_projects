import { BadRequestException, HttpException, HttpStatus, Injectable } from '@nestjs/common';
import { CreateUserDto } from './dto/create-user.dto';
import { UpdateUserDto } from './dto/update-user.dto';
import { NotFoundException } from '@nestjs/common';
import { PrismaService } from 'src/prisma/prisma.service';
import axios from 'axios';
import { User } from './entities/user.entity';
import { join } from 'path';
import { createWriteStream } from 'fs';

@Injectable()
export class UsersService {

	constructor(private prisma: PrismaService) { }


	create(createUserDto: CreateUserDto) {
		return this.prisma.user.create({ data: createUserDto });
	}

	findAll() {
		return this.prisma.user.findMany();
	}

	findOne(id: number) {
		return this.prisma.user.findUnique({ where: { id } });
	}

	update(id: number, updateUserDto: UpdateUserDto) {
		return this.prisma.user.update({

			where: { id },
			data: updateUserDto,
		});
	}

	remove(id: number) {
		return this.prisma.user.delete({ where: { id } });
	}

	getLeaderboard() {
		return this.prisma.user.findMany({
			orderBy: [
				{
					exp: 'desc', //change for experience
				}
			]
		});
	}

	async login(code: string): Promise<any> {
		try {
			let res = await axios.post("https://api.intra.42.fr/oauth/token",
				{
					grant_type: "authorization_code",
					client_id: "u-s4t2ud-bca5b5ca59fdfab1c4827aa0f8698120d89e4d34d19e01b6102dc96f525087cd",
					client_secret: process.env.API_SECRET,
					code: code,
					redirect_uri: "http://localhost:3000/callback"
				}
			)
			console.log(res.data);
			const token = res.data.access_token;
			let user = await axios.get(
				"https://api.intra.42.fr/v2/me",
				{ headers: { "Authorization": `Bearer ${token}` } }
			)
			return ({
				id: user.data.id,
			});
		} catch (err) {
			// console.log(err);
			throw new BadRequestException("Something went wrong with the 42 API.")
		}
	}

	async getFriends(id: number) {
		return await this.prisma.friendship.findMany({
			include: {
				related_user: true,
			},
			where: {
				relating_id: id,
				relation: 'F'
			}
		})
	}

	async getPending(id: number) {
		return await this.prisma.friendship.findMany({
			include: {
				related_user: true
			},
			where: {
				OR: [{ relation: 'R', relating_id: id },
				{ relation: 'S', relating_id: id }]
			},
			orderBy: {
				related_user: {
					username: 'asc'
				}
			}
		})
	}

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
		if (relation_db.length == 0) {
			return relation
		}
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
				blocking_id: +requested,
				blocked_id: +requesting
			}
		});
		if (block.length !== 0) {
			relation.blocking = true;
		}
		return (relation);
	}

	async usernameChange(id: number, newUsername: string) {
		const user = await this.prisma.user.findUnique({
			where: {
				username: newUsername,
			}
		})
		if (user != null) {
			throw new BadRequestException("Username already taken.")
		}
		try {
			await this.prisma.user.update({
				where: {
					id: +id,
				},
				data: {
					username: newUsername,
				}
			})
		} catch (err) {
			throw new NotFoundException(`User with id: ${id} does not exist.`);
		}
		return ("Username changed succesfully.");
	}

	async changeAvatar(id: number, avatar: Express.Multer.File) {
		var re = /(?:\.([^.]+))?$/;
		var fs = require('fs');
		const ext = re.exec(avatar.originalname)[1]

		if (ext !== "gif" && ext !== "png" && ext !== "jpeg" && ext !== "jpg") {
			throw new BadRequestException("Files have to be .gif, .png, .jpg or .jpeg.");
		}
		const filename = id + "." + ext;
		fs.mkdir(join(__dirname, '..', '..', '..', 'uploads'), { recursive: true }, (err) => {
			if (err) throw err;
		});
		const filePath = join(__dirname, '..', '..', '..', 'uploads', filename);
		const writeStream = createWriteStream(filePath);

		writeStream.write(avatar.buffer);
		writeStream.end();
		try {
			await this.prisma.user.update({
				where: {
					id: +id,
				},
				data: {
					avatar: filename,
				}
			})
			return "Avatar changed successfully.";
		} catch (error) {
			throw new NotFoundException(`User with id: ${id} does not exist.`);
		}
	}

	async findById(id: number): Promise<User | null> {
		return this.prisma.user.findUnique({ where: { id } });
	}
}
