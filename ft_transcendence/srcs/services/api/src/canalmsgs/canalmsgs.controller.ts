import {Controller, Get, Post, Body, Patch, Param, Delete, UseGuards} from '@nestjs/common';
import { CanalmsgsService } from './canalmsgs.service';
import { CreateCanalmsgDto } from './dto/create-canalmsg.dto';
import { UpdateCanalmsgDto } from './dto/update-canalmsg.dto';
import {AuthGuard} from "../auth/auth.guards";
import {UserGuard} from "../users/users.guards";

@Controller('messages/canal')
export class CanalmsgsController {
  constructor(private readonly canalmsgsService: CanalmsgsService) {}

  @Post()
  @UseGuards(AuthGuard)
  create(@Body() createCanalmsgDto: CreateCanalmsgDto) {
    return this.canalmsgsService.create(createCanalmsgDto);
  }

  @Get()
  @UseGuards(AuthGuard)
  findAll() {
    return this.canalmsgsService.findAll();
  }

  @Get(':canal_id')
  @UseGuards(AuthGuard)
  fetchManyByCanalId(@Param('canal_id') id: string) {
    return this.canalmsgsService.fetchManyByCanalId(+id);
  }
}