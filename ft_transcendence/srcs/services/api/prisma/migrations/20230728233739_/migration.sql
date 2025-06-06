/*
  Warnings:

  - You are about to drop the column `user_id` on the `User_message` table. All the data in the column will be lost.
  - Added the required column `sender_username` to the `User_message` table without a default value. This is not possible if the table is not empty.

*/
-- DropForeignKey
ALTER TABLE "User_message" DROP CONSTRAINT "User_message_user_id_fkey";

-- AlterTable
ALTER TABLE "User_message" DROP COLUMN "user_id",
ADD COLUMN     "sender_username" TEXT NOT NULL,
ALTER COLUMN "time" SET DATA TYPE TEXT;

-- AddForeignKey
ALTER TABLE "User_message" ADD CONSTRAINT "User_message_sender_username_fkey" FOREIGN KEY ("sender_username") REFERENCES "User"("username") ON DELETE RESTRICT ON UPDATE CASCADE;
