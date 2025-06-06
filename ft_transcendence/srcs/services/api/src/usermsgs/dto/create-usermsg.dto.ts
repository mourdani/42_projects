import { ApiProperty } from "@nestjs/swagger";

export class CreateUsermsgDto {
    @ApiProperty()
    content: string;

    @ApiProperty()
    receiver_id: number;

    @ApiProperty()
    sender_id: number;

    @ApiProperty()
    sender_username: string;
}

