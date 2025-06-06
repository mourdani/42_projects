import { Module } from '@nestjs/common';
import { CanalUserRelationsService } from './canal_user_relations.service';
import { CanalUserRelationsController } from './canal_user_relations.controller';
import { PrismaModule } from '../prisma/prisma.module';

@Module({
  controllers: [CanalUserRelationsController],
  providers: [CanalUserRelationsService],
  imports: [PrismaModule],
})
export class CanalUserRelationsModule {}
