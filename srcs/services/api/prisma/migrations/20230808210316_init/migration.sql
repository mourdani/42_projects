/*
  Warnings:

  - You are about to drop the column `sender_id` on the `User_message` table. All the data in the column will be lost.
  - You are about to drop the `Canal_message` table. If the table is not empty, all the data it contains will be lost.
  - Added the required column `content` to the `User_message` table without a default value. This is not possible if the table is not empty.
  - Added the required column `sender_username` to the `User_message` table without a default value. This is not possible if the table is not empty.

*/
-- DropForeignKey
ALTER TABLE "Canal_message" DROP CONSTRAINT "Canal_message_canal_id_fkey";

-- DropForeignKey
ALTER TABLE "Canal_message" DROP CONSTRAINT "Canal_message_sender_id_fkey";

-- DropForeignKey
ALTER TABLE "User_message" DROP CONSTRAINT "User_message_sender_id_fkey";

-- AlterTable
CREATE SEQUENCE user_message_receiver_id_seq;
ALTER TABLE "User_message" DROP COLUMN "sender_id",
ADD COLUMN     "content" TEXT NOT NULL,
ADD COLUMN     "sender_username" TEXT NOT NULL,
ALTER COLUMN "receiver_id" SET DEFAULT nextval('user_message_receiver_id_seq');
ALTER SEQUENCE user_message_receiver_id_seq OWNED BY "User_message"."receiver_id";

-- DropTable
DROP TABLE "Canal_message";

-- CreateTable
CREATE TABLE "Room_message" (
    "id" SERIAL NOT NULL,
    "content" TEXT NOT NULL,
    "time" TIME NOT NULL,
    "sender_username" TEXT NOT NULL,
    "room_id" SERIAL NOT NULL,

    CONSTRAINT "Room_message_pkey" PRIMARY KEY ("id")
);

-- AddForeignKey
ALTER TABLE "User_message" ADD CONSTRAINT "User_message_sender_username_fkey" FOREIGN KEY ("sender_username") REFERENCES "User"("username") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Room_message" ADD CONSTRAINT "Room_message_room_id_fkey" FOREIGN KEY ("room_id") REFERENCES "Canal"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
