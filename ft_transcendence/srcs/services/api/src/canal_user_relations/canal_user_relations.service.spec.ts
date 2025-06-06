import { Test, TestingModule } from '@nestjs/testing';
import { CanalUserRelationsService } from './canal_user_relations.service';

describe('CanalUserRelationsService', () => {
  let service: CanalUserRelationsService;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      providers: [CanalUserRelationsService],
    }).compile();

    service = module.get<CanalUserRelationsService>(CanalUserRelationsService);
  });

  it('should be defined', () => {
    expect(service).toBeDefined();
  });
});
