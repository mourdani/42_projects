/*
  Warnings:

  - You are about to drop the column `blocks` on the `User` table. All the data in the column will be lost.

*/
-- AlterTable
ALTER TABLE "User" DROP COLUMN "blocks",
ALTER COLUMN "avatar" SET DATA TYPE TEXT;
