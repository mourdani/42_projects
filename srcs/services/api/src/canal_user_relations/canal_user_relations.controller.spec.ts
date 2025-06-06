import { Test, TestingModule } from '@nestjs/testing';
import { CanalUserRelationsController } from './canal_user_relations.controller';
import { CanalUserRelationsService } from './canal_user_relations.service';

describe('CanalUserRelationsController', () => {
  let controller: CanalUserRelationsController;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      controllers: [CanalUserRelationsController],
      providers: [CanalUserRelationsService],
    }).compile();

    controller = module.get<CanalUserRelationsController>(CanalUserRelationsController);
  });

  it('should be defined', () => {
    expect(controller).toBeDefined();
  });
});
