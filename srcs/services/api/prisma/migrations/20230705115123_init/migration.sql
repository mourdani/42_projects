/*
  Warnings:

  - You are about to drop the column `final_score_adv` on the `match_history` table. All the data in the column will be lost.
  - You are about to drop the column `final_score_req` on the `match_history` table. All the data in the column will be lost.
  - You are about to drop the column `player1_id` on the `match_history` table. All the data in the column will be lost.
  - You are about to drop the column `player2_id` on the `match_history` table. All the data in the column will be lost.
  - You are about to drop the column `win` on the `match_history` table. All the data in the column will be lost.
  - Added the required column `loser_id` to the `match_history` table without a default value. This is not possible if the table is not empty.
  - Added the required column `loser_score` to the `match_history` table without a default value. This is not possible if the table is not empty.
  - Added the required column `winner_id` to the `match_history` table without a default value. This is not possible if the table is not empty.
  - Added the required column `winner_score` to the `match_history` table without a default value. This is not possible if the table is not empty.

*/
-- DropForeignKey
ALTER TABLE "match_history" DROP CONSTRAINT "match_history_player1_id_fkey";

-- DropForeignKey
ALTER TABLE "match_history" DROP CONSTRAINT "match_history_player2_id_fkey";

-- AlterTable
ALTER TABLE "match_history" DROP COLUMN "final_score_adv",
DROP COLUMN "final_score_req",
DROP COLUMN "player1_id",
DROP COLUMN "player2_id",
DROP COLUMN "win",
ADD COLUMN     "loser_id" INTEGER NOT NULL,
ADD COLUMN     "loser_score" INTEGER NOT NULL,
ADD COLUMN     "winner_id" INTEGER NOT NULL,
ADD COLUMN     "winner_score" INTEGER NOT NULL;

-- CreateTable
CREATE TABLE "achievement" (
    "achievement_id" INTEGER NOT NULL,
    "name" TEXT NOT NULL,
    "description" TEXT NOT NULL,

    CONSTRAINT "achievement_pkey" PRIMARY KEY ("achievement_id")
);

-- CreateTable
CREATE TABLE "earned_achievement" (
    "user_id" INTEGER NOT NULL,
    "achievement_id" INTEGER NOT NULL,

    CONSTRAINT "earned_achievement_pkey" PRIMARY KEY ("user_id","achievement_id")
);

-- AddForeignKey
ALTER TABLE "match_history" ADD CONSTRAINT "match_history_winner_id_fkey" FOREIGN KEY ("winner_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "match_history" ADD CONSTRAINT "match_history_loser_id_fkey" FOREIGN KEY ("loser_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
