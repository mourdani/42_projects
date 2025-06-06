import { Test, TestingModule } from '@nestjs/testing';
import { CanalmsgsController } from './canalmsgs.controller';
import { CanalmsgsService } from './canalmsgs.service';

describe('CanalmsgsController', () => {
  let controller: CanalmsgsController;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      controllers: [CanalmsgsController],
      providers: [CanalmsgsService],
    }).compile();

    controller = module.get<CanalmsgsController>(CanalmsgsController);
  });

  it('should be defined', () => {
    expect(controller).toBeDefined();
  });
});
