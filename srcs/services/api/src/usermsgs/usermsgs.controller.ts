import {Controller, Get, Post, Body, Patch, Param, Delete, UseGuards} from '@nestjs/common';
import { UsermsgsService } from './usermsgs.service';
import { CreateUsermsgDto } from './dto/create-usermsg.dto';
import { UpdateUsermsgDto } from './dto/update-usermsg.dto';
import {AuthGuard} from "../auth/auth.guards";
import {UserGuard} from "../users/users.guards";

@Controller('messages/user')
export class UsermsgsController {
  constructor(private readonly usermsgsService: UsermsgsService) {}

  @Post()
  @UseGuards(AuthGuard)
  create(@Body() createUsermsgDto: CreateUsermsgDto) {
    return this.usermsgsService.create(createUsermsgDto);
  }

  @Get()
  @UseGuards(AuthGuard)
  findAll() {
    return this.usermsgsService.findAll();
  }

  @Get(':id')
  @UseGuards(AuthGuard) // NOT SURE @UseGuards(AuthGuard, UserGuard) ?
  fetchManyByUserId(@Param('id') id: string) {
    return this.usermsgsService.fetchManyByUserId(+id);
  }
}
