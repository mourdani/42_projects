import {Controller, Get, Post, Body, Patch, Param, Delete, UseGuards} from '@nestjs/common';
import { BlocksService } from './blocks.service';
import { CreateBlockDto } from './dto/create-block.dto';
import { UpdateBlockDto } from './dto/update-block.dto';
import {AuthGuard} from "../auth/auth.guards";
import {UserGuard} from "../users/users.guards";

@Controller('blocks')
export class BlocksController {
  constructor(private readonly blocksService: BlocksService) {}

  @Post()
  @UseGuards(AuthGuard)
  create(@Body() createBlockDto: CreateBlockDto) {
    return this.blocksService.create(createBlockDto);
  }

  @Get(':id')
  @UseGuards(AuthGuard, UserGuard)
  findBlockedUsersByUserId(@Param('id') id: string) {
    return this.blocksService.findBlockedUsersByUserId(+id);
  }

  @Delete(':blockingId/:blockedId')
  @UseGuards(AuthGuard, UserGuard)
  delete(@Param('blockingId') blockingId: string, @Param('blockedId') blockedId: string) {
    return this.blocksService.delete(+blockingId, +blockedId);
  }
}
