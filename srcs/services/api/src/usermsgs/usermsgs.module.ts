import { Module } from '@nestjs/common';
import { UsermsgsService } from './usermsgs.service';
import { UsermsgsController } from './usermsgs.controller';
import { PrismaModule } from 'src/prisma/prisma.module';

@Module({
  controllers: [UsermsgsController],
  providers: [UsermsgsService],
  imports: [PrismaModule]
})
export class UsermsgsModule {}
