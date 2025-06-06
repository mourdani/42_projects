/*
  Warnings:

  - You are about to drop the column `content` on the `User_message` table. All the data in the column will be lost.
  - You are about to drop the column `sender_username` on the `User_message` table. All the data in the column will be lost.
  - Added the required column `sender_id` to the `Canal_message` table without a default value. This is not possible if the table is not empty.
  - Added the required column `sender_id` to the `User_message` table without a default value. This is not possible if the table is not empty.

*/
-- DropForeignKey
ALTER TABLE "User_message" DROP CONSTRAINT "User_message_sender_username_fkey";

-- AlterTable
ALTER TABLE "Canal_message" ADD COLUMN     "sender_id" INTEGER NOT NULL;

-- AlterTable
ALTER TABLE "User_message" DROP COLUMN "content",
DROP COLUMN "sender_username",
ADD COLUMN     "sender_id" INTEGER NOT NULL,
ALTER COLUMN "receiver_id" DROP DEFAULT;
DROP SEQUENCE "user_message_receiver_id_seq";

-- AddForeignKey
ALTER TABLE "User_message" ADD CONSTRAINT "User_message_sender_id_fkey" FOREIGN KEY ("sender_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Canal_message" ADD CONSTRAINT "Canal_message_sender_id_fkey" FOREIGN KEY ("sender_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
