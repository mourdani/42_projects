import { Module } from '@nestjs/common';
import { PrismaModule } from 'src/prisma/prisma.module';
import { RelationsController } from './relations.controller';
import { RelationsService } from './relations.service';

@Module({
  controllers: [RelationsController],
  providers: [RelationsService],
  imports: [PrismaModule],
  exports: [RelationsService],
})
export class RelationsModule {}
