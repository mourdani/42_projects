-- AlterTable
ALTER TABLE "Canal_message" ALTER COLUMN "canal_id" DROP DEFAULT;
DROP SEQUENCE "Canal_message_canal_id_seq";

-- AlterTable
ALTER TABLE "User_message" ALTER COLUMN "receiver_id" DROP DEFAULT;
DROP SEQUENCE "user_message_receiver_id_seq";
