import { ApiProperty } from '@nestjs/swagger';
import * as bcrypt from 'bcrypt';
import {
    IsBoolean,
    IsNotEmpty,
    IsOptional,
    IsString,
    MaxLength,
    MinLength,
    IsNumber,
    IsBase64,
  } from 'class-validator';

export class CreateCanalDto {
    @ApiProperty({ required: true })
    @IsNotEmpty()
    @MaxLength(15)
    @MinLength(3)
    @IsString()
    name:    string

    @ApiProperty()
    type: CanalType;

@ApiProperty(({ required: false }))
  set password(password: string) {
    // Hash the password before storing it
    const saltRounds = 10;
    const hashedPassword = bcrypt.hashSync(password, saltRounds);
    this._password = hashedPassword;
  }

  private _password: string;

  get password(): string {
    return this._password;
  }
}


export enum CanalType {
    Public = "public",
    Protected = "protected"
}
