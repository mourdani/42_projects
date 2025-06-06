import { Injectable } from '@nestjs/common';
import { CreateCanalDto } from './dto/create-canal.dto';
import { UpdateCanalDto } from './dto/update-canal.dto';
import { PrismaService } from 'src/prisma/prisma.service';
import * as bcrypt from 'bcrypt';

@Injectable()
export class CanalsService {
  constructor(private prisma: PrismaService) { }


  async create(createCanalDto: CreateCanalDto) {
    const { password, ...rest } = createCanalDto;

    // Generate a salt to be used for hashing
    const salt = await bcrypt.genSalt(10);

    // Hash the password using the generated salt
    const hashedPassword = await bcrypt.hash(password, salt);

    // Create the canal with the hashed password
    return this.prisma.canal.create({
      data: {
        ...rest,
        password: hashedPassword,
      },
    });
  }


  findAll() {
    return this.prisma.canal.findMany({});
  }
  findOne(id: number) {
    return this.prisma.canal.findUnique({ where: { id } });
  }

  async update(id: number, updateCanalDto: UpdateCanalDto) {
    const { password, ...rest } = updateCanalDto;
    const salt = await bcrypt.genSalt(10);
    const hashedPassword = await bcrypt.hash(password, salt);

    return this.prisma.canal.update({
      where: { id },
      data: {
        ...rest,
        password: hashedPassword,
      },
    });
  }

  remove(id: number) {
    return `This action removes a #${id} canal`;
  }
}
