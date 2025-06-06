import { PartialType } from '@nestjs/swagger';
import { CreateUserDto } from './create-user.dto';
import { newUsername } from 'src/app.controller';

export class UpdateUserDto extends PartialType(CreateUserDto) {}