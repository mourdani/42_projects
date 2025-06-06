/*
  Warnings:

  - You are about to drop the column `mute_duration` on the `canal_user_relation` table. All the data in the column will be lost.
  - You are about to drop the column `mute_time` on the `canal_user_relation` table. All the data in the column will be lost.
  - Added the required column `is_muted` to the `canal_user_relation` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "canal_user_relation" DROP COLUMN "mute_duration",
DROP COLUMN "mute_time",
ADD COLUMN     "is_muted" BOOLEAN NOT NULL;
