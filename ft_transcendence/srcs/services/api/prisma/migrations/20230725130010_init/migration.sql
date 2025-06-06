-- AlterTable
CREATE SEQUENCE match_history_match_id_seq;
ALTER TABLE "match_history" ALTER COLUMN "match_id" SET DEFAULT nextval('match_history_match_id_seq');
ALTER SEQUENCE match_history_match_id_seq OWNED BY "match_history"."match_id";
