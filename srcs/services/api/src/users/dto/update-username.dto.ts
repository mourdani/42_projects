import { ApiProperty } from "@nestjs/swagger";
import { IsNotEmpty, MaxLength, MinLength, IsString } from "class-validator";

export class UpdateUsernameDto {
	@ApiProperty()
	@MaxLength(15)
	@MinLength(3)
	@IsNotEmpty()
	@IsString()
	newUsername: string;
}
