import { PartialType } from '@nestjs/swagger';
import { CreateUsermsgDto } from './create-usermsg.dto';

export class UpdateUsermsgDto extends PartialType(CreateUsermsgDto) {}
