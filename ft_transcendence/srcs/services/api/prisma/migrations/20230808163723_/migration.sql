/*
  Warnings:

  - You are about to drop the `Room_message` table. If the table is not empty, all the data it contains will be lost.

*/
-- DropForeignKey
ALTER TABLE "Room_message" DROP CONSTRAINT "Room_message_room_id_fkey";

-- DropTable
DROP TABLE "Room_message";

-- CreateTable
CREATE TABLE "Canal_message" (
    "id" SERIAL NOT NULL,
    "content" TEXT NOT NULL,
    "time" TIME NOT NULL,
    "sender_username" TEXT NOT NULL,
    "canal_id" SERIAL NOT NULL,

    CONSTRAINT "Canal_message_pkey" PRIMARY KEY ("id")
);

-- AddForeignKey
ALTER TABLE "Canal_message" ADD CONSTRAINT "Canal_message_canal_id_fkey" FOREIGN KEY ("canal_id") REFERENCES "Canal"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
