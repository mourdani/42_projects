import { ApiProperty } from "@nestjs/swagger";

export class CreateCanalmsgDto {
    @ApiProperty()
    content: string;

    @ApiProperty()
    canal_id: number;

    @ApiProperty()
    sender_id: number;

    @ApiProperty()
    sender_username: string;
}

