import { ApiProperty } from '@nestjs/swagger';

export class CreateCanalUserRelationDto {
    @ApiProperty()
    canalId: number;

    @ApiProperty()
    userId: number;

    @ApiProperty()
    isJoined: boolean;

    @ApiProperty()
    isOwner: boolean;

    @ApiProperty()
    isAdmin: boolean;

    @ApiProperty()
    isBanned: boolean;

    @ApiProperty()
    isMuted: boolean;
}
