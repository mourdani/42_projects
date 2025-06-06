import { Injectable } from '@nestjs/common';
import { CreateUsermsgDto } from './dto/create-usermsg.dto';
import { UpdateUsermsgDto } from './dto/update-usermsg.dto';
import { PrismaService } from '../prisma/prisma.service';

@Injectable()
export class UsermsgsService {

  constructor (private prisma: PrismaService) {}

  create(createUsermsgDto: CreateUsermsgDto) {
    return this.prisma.user_message.create({ data: createUsermsgDto });
  }

  findAll() {
    return this.prisma.user_message.findMany();
  }

  fetchManyByUserId(user_id: number) {
    return this.prisma.user_message.findMany({
      // where receiver_id = user_id or sender_id = user_id
      where: {
        OR: [
          { receiver_id: user_id },
          { sender_id: user_id }
        ]
      }
    });
  }
}
