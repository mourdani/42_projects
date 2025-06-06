/*
  Warnings:

  - Changed the type of `time` on the `Room_message` table. No cast exists, the column would be dropped and recreated, which cannot be done if there is data, since the column is required.
  - Changed the type of `time` on the `User_message` table. No cast exists, the column would be dropped and recreated, which cannot be done if there is data, since the column is required.

*/
-- AlterTable
ALTER TABLE "Room_message" DROP COLUMN "time",
ADD COLUMN     "time" TIME NOT NULL;

-- AlterTable
ALTER TABLE "User_message" DROP COLUMN "time",
ADD COLUMN     "time" TIME NOT NULL;
