import { Test, TestingModule } from '@nestjs/testing';
import { CanalmsgsService } from './canalmsgs.service';

describe('CanalmsgsService', () => {
  let service: CanalmsgsService;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      providers: [CanalmsgsService],
    }).compile();

    service = module.get<CanalmsgsService>(CanalmsgsService);
  });

  it('should be defined', () => {
    expect(service).toBeDefined();
  });
});
