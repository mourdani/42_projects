import {Controller, Get, Post, Body, Patch, Param, Delete, UseGuards} from '@nestjs/common';
import { CanalUserRelationsService } from './canal_user_relations.service';
import { CreateCanalUserRelationDto } from './dto/create-canal_user_relation.dto';
import { UpdateCanalUserRelationDto } from './dto/update-canal_user_relation.dto';
import {AuthGuard} from "../auth/auth.guards";
import {BlockGuard} from "../relations/relations.guards";
import { UserGuard } from 'src/users/users.guards';

@Controller('canal-user-relations')
export class CanalUserRelationsController {
  constructor(private readonly canalUserRelationsService: CanalUserRelationsService) {}

  @Post()
  @UseGuards(AuthGuard)
  create(@Body() createCanalUserRelationDto: CreateCanalUserRelationDto) {
    return this.canalUserRelationsService.create(createCanalUserRelationDto);
  }

  @Get()
  @UseGuards(AuthGuard)
  findAll() {
    return this.canalUserRelationsService.findAll();
  }

  @Get(':id')
  @UseGuards(AuthGuard, BlockGuard)
  findAllByUserId(@Param('id') userId: string) {
    return this.canalUserRelationsService.findAllByUserId(+userId);
  }

  @Get(':canal_id/:id')
  @UseGuards(AuthGuard)
  findAllByCanalIdAndUserId(@Param('canal_id') canalId: string, @Param('id') userId: string) {
    return this.canalUserRelationsService.findAllByCanalIdAndUserId(+canalId, +userId);
  }


  @Patch(':canal_id/:id')
  @UseGuards(AuthGuard)
  update(@Param('canal_id') canalId: string, @Param('id') userId: string, @Body() updateCanalUserRelationDto: UpdateCanalUserRelationDto) {
    return this.canalUserRelationsService.update(+canalId, +userId, updateCanalUserRelationDto);

  }

  @Delete(':canal_id/:id')
  @UseGuards(AuthGuard)
  remove(@Param('canal_id') canalId: string, @Param('user_id') userId: string) {
    return this.canalUserRelationsService.remove(+canalId, +userId);
  }
}
