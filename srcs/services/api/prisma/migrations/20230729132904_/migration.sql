/*
  Warnings:

  - You are about to drop the `Canal` table. If the table is not empty, all the data it contains will be lost.
  - You are about to drop the `Canal_message` table. If the table is not empty, all the data it contains will be lost.

*/
-- DropForeignKey
ALTER TABLE "Canal_message" DROP CONSTRAINT "Canal_message_canal_id_fkey";

-- DropForeignKey
ALTER TABLE "canal_user_relation" DROP CONSTRAINT "canal_user_relation_canal_id_fkey";

-- DropTable
DROP TABLE "Canal";

-- DropTable
DROP TABLE "Canal_message";

-- CreateTable
CREATE TABLE "Room" (
    "id" SERIAL NOT NULL,
    "name" TEXT NOT NULL,
    "type" "canal_type" NOT NULL DEFAULT 'public',
    "password" TEXT,

    CONSTRAINT "Room_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "Room_message" (
    "id" SERIAL NOT NULL,
    "content" TEXT NOT NULL,
    "time" TIMESTAMP NOT NULL,
    "canal_id" INTEGER NOT NULL,

    CONSTRAINT "Room_message_pkey" PRIMARY KEY ("id")
);

-- CreateIndex
CREATE UNIQUE INDEX "Room_name_key" ON "Room"("name");

-- AddForeignKey
ALTER TABLE "User_message" ADD CONSTRAINT "User_message_receiver_id_fkey" FOREIGN KEY ("receiver_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Room_message" ADD CONSTRAINT "Room_message_canal_id_fkey" FOREIGN KEY ("canal_id") REFERENCES "Room"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "canal_user_relation" ADD CONSTRAINT "canal_user_relation_canal_id_fkey" FOREIGN KEY ("canal_id") REFERENCES "Room"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
