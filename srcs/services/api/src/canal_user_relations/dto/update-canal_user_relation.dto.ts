import { PartialType } from '@nestjs/swagger';
import { CreateCanalUserRelationDto } from './create-canal_user_relation.dto';

export class UpdateCanalUserRelationDto extends PartialType(CreateCanalUserRelationDto) {}
