/*
  Warnings:

  - You are about to drop the `Room` table. If the table is not empty, all the data it contains will be lost.
  - You are about to drop the `room_user_relation` table. If the table is not empty, all the data it contains will be lost.

*/
-- CreateEnum
CREATE TYPE "canal_type" AS ENUM ('public', 'protected');

-- DropForeignKey
ALTER TABLE "Room_message" DROP CONSTRAINT "Room_message_room_id_fkey";

-- DropForeignKey
ALTER TABLE "room_user_relation" DROP CONSTRAINT "room_user_relation_room_id_fkey";

-- DropForeignKey
ALTER TABLE "room_user_relation" DROP CONSTRAINT "room_user_relation_user_id_fkey";

-- DropTable
DROP TABLE "Room";

-- DropTable
DROP TABLE "room_user_relation";

-- DropEnum
DROP TYPE "room_type";

-- CreateTable
CREATE TABLE "Canal" (
    "id" SERIAL NOT NULL,
    "name" TEXT NOT NULL,
    "type" "canal_type" NOT NULL DEFAULT 'public',
    "password" TEXT,

    CONSTRAINT "Canal_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "canal_user_relation" (
    "canal_id" INTEGER NOT NULL,
    "user_id" INTEGER NOT NULL,
    "is_joined" BOOLEAN NOT NULL,
    "is_owner" BOOLEAN NOT NULL,
    "is_admin" BOOLEAN NOT NULL,
    "is_banned" BOOLEAN NOT NULL,
    "mute_time" TIME NOT NULL,
    "mute_duration" TIME NOT NULL,

    CONSTRAINT "canal_user_relation_pkey" PRIMARY KEY ("canal_id","user_id")
);

-- CreateIndex
CREATE UNIQUE INDEX "Canal_name_key" ON "Canal"("name");

-- AddForeignKey
ALTER TABLE "Room_message" ADD CONSTRAINT "Room_message_room_id_fkey" FOREIGN KEY ("room_id") REFERENCES "Canal"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "canal_user_relation" ADD CONSTRAINT "canal_user_relation_canal_id_fkey" FOREIGN KEY ("canal_id") REFERENCES "Canal"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "canal_user_relation" ADD CONSTRAINT "canal_user_relation_user_id_fkey" FOREIGN KEY ("user_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
