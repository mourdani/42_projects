-- AlterTable
ALTER TABLE "achievement" ALTER COLUMN "lose_requirement" DROP NOT NULL,
ALTER COLUMN "play_requirement" DROP NOT NULL,
ALTER COLUMN "win_requirement" DROP NOT NULL;
