-- AlterTable
CREATE SEQUENCE user_message_receiver_id_seq;
ALTER TABLE "User_message" ALTER COLUMN "receiver_id" SET DEFAULT nextval('user_message_receiver_id_seq');
ALTER SEQUENCE user_message_receiver_id_seq OWNED BY "User_message"."receiver_id";
