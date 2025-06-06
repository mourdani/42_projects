import { Injectable, StreamableFile } from '@nestjs/common';
import { createReadStream } from 'fs';
import { join } from 'path';

@Injectable()
export class AppService {
	getHello(): string {
		return 'Hello World!';
	}

	checkPermission(token: string) {
		
	}

	getFile(filename: string) {
		const filePath = join(__dirname, '..', '..', 'uploads', filename);
		const file = createReadStream(filePath);
		return new StreamableFile(file);
	}
}
