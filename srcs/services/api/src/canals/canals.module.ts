import { Module } from '@nestjs/common';
import { CanalsService } from './canals.service';
import { CanalsController } from './canals.controller';
import { PrismaModule } from 'src/prisma/prisma.module';

@Module({
  controllers: [CanalsController],
  providers: [CanalsService],
  imports: [PrismaModule],
})

export class CanalsModule {}
