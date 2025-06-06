import { Test, TestingModule } from '@nestjs/testing';
import { UsermsgsService } from './usermsgs.service';

describe('UsermsgsService', () => {
  let service: UsermsgsService;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      providers: [UsermsgsService],
    }).compile();

    service = module.get<UsermsgsService>(UsermsgsService);
  });

  it('should be defined', () => {
    expect(service).toBeDefined();
  });
});
