/*
  Warnings:

  - The `type` column on the `Room` table would be dropped and recreated. This will lead to data loss if there is data in the column.
  - You are about to drop the column `canal_id` on the `Room_message` table. All the data in the column will be lost.
  - You are about to drop the `canal_user_relation` table. If the table is not empty, all the data it contains will be lost.
  - Added the required column `sender_username` to the `Room_message` table without a default value. This is not possible if the table is not empty.

*/
-- CreateEnum
CREATE TYPE "room_type" AS ENUM ('public', 'protected');

-- DropForeignKey
ALTER TABLE "Room_message" DROP CONSTRAINT "Room_message_canal_id_fkey";

-- DropForeignKey
ALTER TABLE "canal_user_relation" DROP CONSTRAINT "canal_user_relation_canal_id_fkey";

-- DropForeignKey
ALTER TABLE "canal_user_relation" DROP CONSTRAINT "canal_user_relation_user_id_fkey";

-- AlterTable
ALTER TABLE "Room" DROP COLUMN "type",
ADD COLUMN     "type" "room_type" NOT NULL DEFAULT 'public';

-- AlterTable
ALTER TABLE "Room_message" DROP COLUMN "canal_id",
ADD COLUMN     "room_id" SERIAL NOT NULL,
ADD COLUMN     "sender_username" TEXT NOT NULL,
ALTER COLUMN "time" SET DATA TYPE TEXT;

-- DropTable
DROP TABLE "canal_user_relation";

-- DropEnum
DROP TYPE "canal_type";

-- CreateTable
CREATE TABLE "room_user_relation" (
    "room_id" INTEGER NOT NULL,
    "user_id" INTEGER NOT NULL,
    "is_joined" BOOLEAN NOT NULL,
    "is_owner" BOOLEAN NOT NULL,
    "is_admin" BOOLEAN NOT NULL,
    "is_banned" BOOLEAN NOT NULL,
    "mute_time" TIME NOT NULL,
    "mute_duration" TIME NOT NULL,

    CONSTRAINT "room_user_relation_pkey" PRIMARY KEY ("room_id","user_id")
);

-- AddForeignKey
ALTER TABLE "Room_message" ADD CONSTRAINT "Room_message_room_id_fkey" FOREIGN KEY ("room_id") REFERENCES "Room"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "room_user_relation" ADD CONSTRAINT "room_user_relation_room_id_fkey" FOREIGN KEY ("room_id") REFERENCES "Room"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "room_user_relation" ADD CONSTRAINT "room_user_relation_user_id_fkey" FOREIGN KEY ("user_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
