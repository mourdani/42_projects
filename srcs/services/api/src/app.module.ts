import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { UsersModule } from './users/users.module';
import { AuthModule } from './auth/auth.module';
import { RelationsModule } from './relations/relations.module';
import { GameModule } from './game/game.module';
import { CanalsModule } from './canals/canals.module';
import { CanalUserRelationsModule } from './canal_user_relations/canal_user_relations.module';
import { CanalmsgsModule } from './canalmsgs/canalmsgs.module';
import { UsermsgsModule } from './usermsgs/usermsgs.module';
import { BlocksModule } from './blocks/blocks.module';

@Module({
  imports: [UsersModule, AuthModule, RelationsModule, GameModule, CanalsModule, CanalUserRelationsModule, CanalmsgsModule, UsermsgsModule, BlocksModule],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule {}
