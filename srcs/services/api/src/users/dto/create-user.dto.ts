import { ApiProperty } from '@nestjs/swagger';
import {
  IsNotEmpty,
  IsOptional,
  IsString,
  MaxLength,
  MinLength,
  IsNumber,
  IsBase64,
} from 'class-validator';
// 

export class CreateUserDto {
  @IsNotEmpty()
  @IsNumber()
  id: number;

  @ApiProperty()
  @IsNotEmpty()
  @MaxLength(15)
  @MinLength(3)
  @IsString()
  username: string;

  @ApiProperty()
  avatar: string
}
