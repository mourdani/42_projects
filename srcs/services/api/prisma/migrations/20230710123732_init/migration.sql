/*
  Warnings:

  - Changed the type of `time` on the `match_history` table. No cast exists, the column would be dropped and recreated, which cannot be done if there is data, since the column is required.

*/
-- AlterTable
ALTER TABLE "match_history" DROP COLUMN "time",
ADD COLUMN     "time" TIMESTAMP NOT NULL;
