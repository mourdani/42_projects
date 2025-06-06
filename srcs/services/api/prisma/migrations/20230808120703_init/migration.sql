-- CreateTable
CREATE TABLE "TwoFASecret" (
    "id" INTEGER NOT NULL,
    "twoFASecret" JSONB NOT NULL,

    CONSTRAINT "TwoFASecret_pkey" PRIMARY KEY ("id")
);
