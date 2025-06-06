import { Module } from '@nestjs/common';
import { BlocksService } from './blocks.service';
import { BlocksController } from './blocks.controller';
import { PrismaModule } from 'src/prisma/prisma.module';

@Module({
  controllers: [BlocksController],
  providers: [BlocksService],
  imports: [PrismaModule]
})
export class BlocksModule {}
