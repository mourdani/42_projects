/*
  Warnings:

  - You are about to drop the column `twoFactorAuthenticationSecret` on the `User` table. All the data in the column will be lost.

*/
-- AlterTable
ALTER TABLE "User" DROP COLUMN "twoFactorAuthenticationSecret",
ADD COLUMN     "twoFactorAuthenticationSecret32" TEXT,
ADD COLUMN     "twoFactorAuthenticationSecretURL" TEXT;
