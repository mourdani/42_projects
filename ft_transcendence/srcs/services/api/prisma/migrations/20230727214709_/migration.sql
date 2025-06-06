-- CreateTable
CREATE TABLE "Message" (
    "id" SERIAL NOT NULL,
    "content" TEXT NOT NULL,
    "time" TIMESTAMP NOT NULL,
    "user_id" INTEGER NOT NULL,
    "canal_id" INTEGER NOT NULL,

    CONSTRAINT "Message_pkey" PRIMARY KEY ("id")
);

-- AddForeignKey
ALTER TABLE "Message" ADD CONSTRAINT "Message_user_id_fkey" FOREIGN KEY ("user_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Message" ADD CONSTRAINT "Message_canal_id_fkey" FOREIGN KEY ("canal_id") REFERENCES "Canal"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
