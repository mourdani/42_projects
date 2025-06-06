import { Test, TestingModule } from '@nestjs/testing';
import { UsermsgsController } from './usermsgs.controller';
import { UsermsgsService } from './usermsgs.service';

describe('UsermsgsController', () => {
  let controller: UsermsgsController;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      controllers: [UsermsgsController],
      providers: [UsermsgsService],
    }).compile();

    controller = module.get<UsermsgsController>(UsermsgsController);
  });

  it('should be defined', () => {
    expect(controller).toBeDefined();
  });
});
