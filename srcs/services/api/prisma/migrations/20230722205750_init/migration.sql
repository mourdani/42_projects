/*
  Warnings:

  - The values [private] on the enum `canal_type` will be removed. If these variants are still used in the database, this will fail.

*/
-- AlterEnum
BEGIN;
CREATE TYPE "canal_type_new" AS ENUM ('public', 'protected');
ALTER TABLE "Canal" ALTER COLUMN "type" DROP DEFAULT;
ALTER TABLE "Canal" ALTER COLUMN "type" TYPE "canal_type_new" USING ("type"::text::"canal_type_new");
ALTER TYPE "canal_type" RENAME TO "canal_type_old";
ALTER TYPE "canal_type_new" RENAME TO "canal_type";
DROP TYPE "canal_type_old";
ALTER TABLE "Canal" ALTER COLUMN "type" SET DEFAULT 'public';
COMMIT;
