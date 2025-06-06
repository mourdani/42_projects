import { ApiProperty } from "@nestjs/swagger";

export class UpdateExpDto {
  @ApiProperty()
  newExp: number
}
  