import { Injectable } from '@nestjs/common';
import { CreateCanalmsgDto } from './dto/create-canalmsg.dto';
import { UpdateCanalmsgDto } from './dto/update-canalmsg.dto';
import { PrismaService } from '../prisma/prisma.service';



@Injectable()
export class CanalmsgsService {

  constructor(private prisma: PrismaService) {}

  create(createCanalmsgDto: CreateCanalmsgDto) {
    return this.prisma.canal_message.create({
      data: createCanalmsgDto
      }
    );
  }

  findAll() {
    return this.prisma.canal_message.findMany();
  }

  fetchManyByCanalId(canal_id: number) {
    return this.prisma.canal_message.findMany({
      where: {
        canal_id: canal_id
      }
    });
  }
}
