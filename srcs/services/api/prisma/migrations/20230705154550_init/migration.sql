-- AddForeignKey
ALTER TABLE "earned_achievement" ADD CONSTRAINT "earned_achievement_user_id_fkey" FOREIGN KEY ("user_id") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "earned_achievement" ADD CONSTRAINT "earned_achievement_achievement_id_fkey" FOREIGN KEY ("achievement_id") REFERENCES "achievement"("achievement_id") ON DELETE RESTRICT ON UPDATE CASCADE;
