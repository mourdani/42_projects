/*
  Warnings:

  - You are about to drop the column `twoFactorAuthenticationSecret32` on the `User` table. All the data in the column will be lost.
  - You are about to drop the column `twoFactorAuthenticationSecretURL` on the `User` table. All the data in the column will be lost.

*/
-- AlterTable
ALTER TABLE "User" DROP COLUMN "twoFactorAuthenticationSecret32",
DROP COLUMN "twoFactorAuthenticationSecretURL",
ADD COLUMN     "twoFactorAuthenticationSecret" JSONB;
