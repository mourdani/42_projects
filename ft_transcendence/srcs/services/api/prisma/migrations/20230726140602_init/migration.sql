/*
  Warnings:

  - Added the required column `lose_requirement` to the `achievement` table without a default value. This is not possible if the table is not empty.
  - Added the required column `play_requirement` to the `achievement` table without a default value. This is not possible if the table is not empty.
  - Added the required column `win_requirement` to the `achievement` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "achievement" ADD COLUMN     "lose_requirement" INTEGER NOT NULL,
ADD COLUMN     "play_requirement" INTEGER NOT NULL,
ADD COLUMN     "win_requirement" INTEGER NOT NULL;
