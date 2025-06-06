import { Controller, Get, Post, Body, Patch, Param, UseGuards, UseInterceptors, BadRequestException } from '@nestjs/common';
import { UsersService } from './users.service';
import { CreateUserDto } from './dto/create-user.dto';
import { AuthGuard } from 'src/auth/auth.guards';
import { UploadedFile, NotFoundException } from '@nestjs/common';
import { FileInterceptor } from '@nestjs/platform-express';
import { BlockGuard } from 'src/relations/relations.guards';
import { UserGuard } from './users.guards';
import { UpdateUsernameDto } from './dto/update-username.dto';

@Controller('users')
export class UsersController {
	constructor(private readonly usersService: UsersService) { }

	@Post(':id')
	@UseGuards(AuthGuard, UserGuard)
	create(@Body() createUserDto: CreateUserDto) {
		console.log("HERE");
		return this.usersService.create(createUserDto);
	}

	@Get()
	@UseGuards(AuthGuard)
	findAll() {
		return this.usersService.findAll();
	}

	@Get('/leaderboard')
	@UseGuards(AuthGuard)
	async leaderboard() {
		console.log("/leaderboard");
		return await this.usersService.getLeaderboard();
	}

	@Get(':id')
	@UseGuards(AuthGuard)
	async findOne(@Param('id') id: string) {
		const user = await this.usersService.findOne(+id);
		if (!user) {
			throw new NotFoundException(`User with id: ${id} does not exist.`);
		}
		return user;
	}

	@Get('friends/:id')
	@UseGuards(AuthGuard, BlockGuard)
	async getFriends(@Param('id') id: string) {
		console.log("/users/friends/" + id);
		if (!(await this.usersService.findOne(+id))) {
			throw new NotFoundException(`User with id: ${id} does not exist.`);
		}
		const friends = await this.usersService.getFriends(+id);
		return friends;
	}

	@Get('pending/:id')
	@UseGuards(AuthGuard, UserGuard)
	async getPending(@Param('id') id: string) {
		console.log("/users/pending/" + id);
		const pending = await this.usersService.getPending(+id);
		return pending;
	}

	@Patch('/:id/change_username')
	@UseGuards(AuthGuard, UserGuard)
	changeUsername(@Param("id") id: number, @Body() UpdateUsernameDto: UpdateUsernameDto) {
		console.log("/user/" + id + "/change_username");
		return (this.usersService.usernameChange(id, UpdateUsernameDto.newUsername));
	}

	@Patch('/:id/change_avatar')
	@UseGuards(AuthGuard, UserGuard)
	@UseInterceptors(FileInterceptor('avatar'))
	changeAvatar(@Param("id") id: number, @UploadedFile() avatar: Express.Multer.File) {
		if (avatar === undefined) {
			throw new BadRequestException("File must be profided.");
		}
		return this.usersService.changeAvatar(id, avatar);
	}
}
