import {Controller, Get, Post, Body, Patch, Param, Delete, UseGuards} from '@nestjs/common';
import { CanalsService } from './canals.service';
import { CreateCanalDto } from './dto/create-canal.dto';
import { UpdateCanalDto } from './dto/update-canal.dto';
import {AuthGuard} from "../auth/auth.guards";
import {UserGuard} from "../users/users.guards";

@Controller('canals')
export class CanalsController {
  constructor(private readonly canalsService: CanalsService) {}

  @Post()
  @UseGuards(AuthGuard)
  create(@Body() createCanalDto: CreateCanalDto) {
	  return this.canalsService.create(createCanalDto);
  }

  @Get()
  @UseGuards(AuthGuard)
  findAll() {
    return this.canalsService.findAll();
  }

  @Get(':id')
  @UseGuards(AuthGuard)
  findOne(@Param('id') id: string) {
    return this.canalsService.findOne(+id);
  }

  @Patch(':id')
  @UseGuards(AuthGuard)
  update(@Param('id') id: string, @Body() updateCanalDto: UpdateCanalDto) {
    return this.canalsService.update(+id, updateCanalDto);
  }

  @Delete(':id')
  @UseGuards(AuthGuard)
  remove(@Param('id') id: string) {
    return this.canalsService.remove(+id);
  }
}
