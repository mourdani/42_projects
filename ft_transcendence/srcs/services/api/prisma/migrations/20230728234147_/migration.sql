/*
  Warnings:

  - Added the required column `sender_id` to the `User_message` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "User_message" ADD COLUMN     "sender_id" INTEGER NOT NULL;
