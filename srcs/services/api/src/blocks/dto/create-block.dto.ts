import { ApiProperty } from "@nestjs/swagger";
import { IsNumber } from "class-validator";

export class CreateBlockDto {
    @ApiProperty()
	@IsNumber()
    blockingId: number;

    @ApiProperty()
	@IsNumber()
    blockedId: number;
}
