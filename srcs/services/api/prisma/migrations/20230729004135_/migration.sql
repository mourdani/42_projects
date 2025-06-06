/*
  Warnings:

  - You are about to drop the column `sender_id` on the `User_message` table. All the data in the column will be lost.

*/
-- AlterTable
ALTER TABLE "User_message" DROP COLUMN "sender_id",
ADD COLUMN     "receiver_id" INTEGER NOT NULL DEFAULT 0;
