/*
  Warnings:

  - You are about to drop the column `avatar_id` on the `User` table. All the data in the column will be lost.

*/
-- CreateEnum
CREATE TYPE "canal_type" AS ENUM ('public', 'private', 'protected');

-- CreateEnum
CREATE TYPE "relation_status" AS ENUM ('F', 'S', 'R');

-- AlterTable
ALTER TABLE "User" DROP COLUMN "avatar_id",
ADD COLUMN     "avatar" BYTEA,
ADD COLUMN     "blocks" INTEGER[],
ADD COLUMN     "exp" INTEGER NOT NULL DEFAULT 0;

-- CreateTable
CREATE TABLE "Canal" (
    "id" SERIAL NOT NULL,
    "name" TEXT NOT NULL,
    "type" "canal_type" NOT NULL DEFAULT 'public',
    "password" TEXT NOT NULL,

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
    "mute" TIME NOT NULL,
    "mute_duration" TIME NOT NULL,

    CONSTRAINT "canal_user_relation_pkey" PRIMARY KEY ("canal_id","user_id")
);

-- CreateTable
CREATE TABLE "Friendship" (
    "relating_id" INTEGER NOT NULL,
    "related_id" INTEGER NOT NULL,
    "relation" "relation_status" NOT NULL,

    CONSTRAINT "Friendship_pkey" PRIMARY KEY ("relating_id","related_id")
);

-- CreateTable
CREATE TABLE "match_history" (
    "match_id" INTEGER NOT NULL,
    "player1_id" INTEGER NOT NULL,
    "player2_id" INTEGER NOT NULL,
    "time" TIME NOT NULL,
    "win" BOOLEAN NOT NULL,
    "final_score_req" INTEGER NOT NULL,
    "final_score_adv" INTEGER NOT NULL,

    CONSTRAINT "match_history_pkey" PRIMARY KEY ("match_id")
);

-- CreateTable
CREATE TABLE "Block" (
    "blocking_id" INTEGER NOT NULL,
    "blocked_id" INTEGER NOT NULL,

    CONSTRAINT "Block_pkey" PRIMARY KEY ("blocking_id","blocked_id")
);

-- CreateIndex
CREATE UNIQUE INDEX "Canal_name_key" ON "Canal"("name");

-- AddForeignKey
ALTER TABLE "canal_user_relation" ADD CONSTRAINT "canal_user_relation_canal_id_fkey" FOREIGN KEY ("canal_id") REFERENCES "Canal"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "canal_user_relation" ADD CONSTRAINT "canal_user_relation_user_id_fkey" FOREIGN KEY ("user_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Friendship" ADD CONSTRAINT "Friendship_relating_id_fkey" FOREIGN KEY ("relating_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Friendship" ADD CONSTRAINT "Friendship_related_id_fkey" FOREIGN KEY ("related_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "match_history" ADD CONSTRAINT "match_history_player1_id_fkey" FOREIGN KEY ("player1_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "match_history" ADD CONSTRAINT "match_history_player2_id_fkey" FOREIGN KEY ("player2_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Block" ADD CONSTRAINT "Block_blocking_id_fkey" FOREIGN KEY ("blocking_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Block" ADD CONSTRAINT "Block_blocked_id_fkey" FOREIGN KEY ("blocked_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
