/*
  Warnings:

  - You are about to drop the `Message` table. If the table is not empty, all the data it contains will be lost.

*/
-- DropForeignKey
ALTER TABLE "Message" DROP CONSTRAINT "Message_canal_id_fkey";

-- DropForeignKey
ALTER TABLE "Message" DROP CONSTRAINT "Message_user_id_fkey";

-- DropTable
DROP TABLE "Message";

-- CreateTable
CREATE TABLE "User_message" (
    "id" SERIAL NOT NULL,
    "content" TEXT NOT NULL,
    "time" TIMESTAMP NOT NULL,
    "user_id" INTEGER NOT NULL,

    CONSTRAINT "User_message_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "Canal_message" (
    "id" SERIAL NOT NULL,
    "content" TEXT NOT NULL,
    "time" TIMESTAMP NOT NULL,
    "canal_id" INTEGER NOT NULL,

    CONSTRAINT "Canal_message_pkey" PRIMARY KEY ("id")
);

-- AddForeignKey
ALTER TABLE "User_message" ADD CONSTRAINT "User_message_user_id_fkey" FOREIGN KEY ("user_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Canal_message" ADD CONSTRAINT "Canal_message_canal_id_fkey" FOREIGN KEY ("canal_id") REFERENCES "Canal"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
