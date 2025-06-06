import { PartialType } from '@nestjs/swagger';
import { CreateCanalmsgDto } from './create-canalmsg.dto';

export class UpdateCanalmsgDto extends PartialType(CreateCanalmsgDto) {
}
