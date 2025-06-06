/*
  Warnings:

  - You are about to drop the column `mute` on the `canal_user_relation` table. All the data in the column will be lost.
  - Added the required column `mute_time` to the `canal_user_relation` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "canal_user_relation" DROP COLUMN "mute",
ADD COLUMN     "mute_time" TIME NOT NULL;
