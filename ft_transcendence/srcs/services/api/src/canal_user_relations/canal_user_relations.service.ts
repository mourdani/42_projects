import { Injectable } from '@nestjs/common';
import { CreateCanalUserRelationDto } from './dto/create-canal_user_relation.dto';
import { UpdateCanalUserRelationDto } from './dto/update-canal_user_relation.dto';
import { PrismaService } from '../prisma/prisma.service';

@Injectable()
export class CanalUserRelationsService {

  constructor(private prisma: PrismaService) {}

create(createCanalUserRelationDto: CreateCanalUserRelationDto) {
  try {
    return this.prisma.canal_user_relation.create({
      data: {
        canal_id: createCanalUserRelationDto.canalId,
        user_id: createCanalUserRelationDto.userId,
        is_joined: createCanalUserRelationDto.isJoined,
        is_owner: createCanalUserRelationDto.isOwner,
        is_admin: createCanalUserRelationDto.isAdmin,
        is_banned: createCanalUserRelationDto.isBanned,
        is_muted: createCanalUserRelationDto.isMuted,
      },
    });
  } catch (error) {
    console.log(error);
    throw new Error('Failed to create canal_user_relation.');
  }
}

  findAll() {
    return this.prisma.canal_user_relation.findMany();
  }

  findAllByUserId(userId: number) {
    return this.prisma.canal_user_relation.findMany({ where: { user_id: userId } });
  }
  
  findAllByCanalIdAndUserId(canalId: number, userId: number) {
    return this.prisma.canal_user_relation.findMany({ where: { canal_id: canalId, user_id: userId } });
  }

update(canalId, userId, updateCanalUserRelationDto) {
  try {
    return this.prisma.canal_user_relation.update({
      where: { canal_id_user_id: { canal_id: canalId, user_id: userId } },
      data: {
        is_joined: updateCanalUserRelationDto.isJoined,
        is_owner: updateCanalUserRelationDto.isOwner,
        is_admin: updateCanalUserRelationDto.isAdmin,
        is_banned: updateCanalUserRelationDto.isBanned,
        is_muted: updateCanalUserRelationDto.isMuted,
      },
    });
  } catch (error) {
    console.log(error);
    throw new Error('Failed to update canal_user_relation.');
  }
}

  remove(canalId: number, userId: number) {
    return this.prisma.canal_user_relation.delete({ where: { canal_id_user_id: { canal_id: canalId, user_id: userId } } });
  }
}
