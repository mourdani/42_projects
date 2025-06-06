import { Module } from '@nestjs/common';
import { CanalmsgsService } from './canalmsgs.service';
import { CanalmsgsController } from './canalmsgs.controller';
import { PrismaModule } from '../prisma/prisma.module';

@Module({
  controllers: [CanalmsgsController],
  providers: [CanalmsgsService],
  imports: [PrismaModule]
})
export class CanalmsgsModule {}
