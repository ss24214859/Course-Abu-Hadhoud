CREATE TABLE "Persons"(
    "PersonID" INT NOT NULL,
    "Name" NVARCHAR(100) NOT NULL,
    "Address" NVARCHAR(200) NOT NULL,
    "ContactINFO" NVARCHAR(100) NOT NULL
);
ALTER TABLE
    "Persons" ADD CONSTRAINT "persons_personid_primary" PRIMARY KEY("PersonID");
CREATE TABLE "Members"(
    "MemberID" INT NOT NULL,
    "PersonID" BIGINT NULL,
    "EmergencyINFO" NVARCHAR(100) NOT NULL,
    "LastBeltRank" INT NULL,
    "IsActive" BIT NOT NULL
);
ALTER TABLE
    "Members" ADD CONSTRAINT "members_memberid_primary" PRIMARY KEY("MemberID");
CREATE UNIQUE INDEX "members_personid_unique" ON
    "Members"("PersonID");
CREATE TABLE "Instructors"(
    "InstructorID" INT NOT NULL,
    "PersonID" INT NOT NULL,
    "Qualifications" NVARCHAR(100) NOT NULL
);
ALTER TABLE
    "Instructors" ADD CONSTRAINT "instructors_instructorid_primary" PRIMARY KEY("InstructorID");
CREATE UNIQUE INDEX "instructors_personid_unique" ON
    "Instructors"("PersonID");
CREATE TABLE "SubscriptionPeriods"(
    "SubscriptionPeriodID" INT NOT NULL,
    "StartDate" DATE NOT NULL,
    "EndDate" DATE NOT NULL,
    "Fees" INT NOT NULL,
    "PaymentID" INT NOT NULL,
    "MemberID" INT NOT NULL
);
ALTER TABLE
    "SubscriptionPeriods" ADD CONSTRAINT "subscriptionperiods_subscriptionperiodid_primary" PRIMARY KEY("SubscriptionPeriodID");
CREATE UNIQUE INDEX "subscriptionperiods_paymentid_unique" ON
    "SubscriptionPeriods"("PaymentID");
CREATE TABLE "Payments"(
    "PaymentID" INT NOT NULL,
    "Amount" INT NOT NULL,
    "Date" DATE NOT NULL,
    "status" NVARCHAR(100) NOT NULL,
    "MemberID" BIGINT NOT NULL
);
ALTER TABLE
    "Payments" ADD CONSTRAINT "payments_paymentid_primary" PRIMARY KEY("PaymentID");
CREATE TABLE "BeltRankTests"(
    "BeltRankTestID" INT NOT NULL,
    "TestDate" DATE NOT NULL,
    "Result" NVARCHAR(100) NOT NULL,
    "BeltRankID" INT NOT NULL,
    "PaymentID" INT NOT NULL,
    "MemberID" INT NOT NULL,
    "InstructorID" BIGINT NOT NULL
);
ALTER TABLE
    "BeltRankTests" ADD CONSTRAINT "beltranktests_beltranktestid_primary" PRIMARY KEY("BeltRankTestID");
CREATE UNIQUE INDEX "beltranktests_paymentid_unique" ON
    "BeltRankTests"("PaymentID");
CREATE TABLE "BeltRanks"(
    "BeltRankID" INT NOT NULL,
    "RankName" NVARCHAR(100) NOT NULL,
    "TestFees" INT NOT NULL
);
ALTER TABLE
    "BeltRanks" ADD CONSTRAINT "beltranks_beltrankid_primary" PRIMARY KEY("BeltRankID");
CREATE UNIQUE INDEX "beltranks_rankname_unique" ON
    "BeltRanks"("RankName");
CREATE TABLE "MemberInstructors"(
    "AssignmentID" INT NOT NULL,
    "MemberID" INT NOT NULL,
    "InstructorID" INT NOT NULL,
    "AssignDate" DATE NOT NULL,
    "EndDate" DATE NOT NULL
);
ALTER TABLE
    "MemberInstructors" ADD CONSTRAINT "memberinstructors_assignmentid_primary" PRIMARY KEY("AssignmentID");
ALTER TABLE
    "SubscriptionPeriods" ADD CONSTRAINT "subscriptionperiods_memberid_foreign" FOREIGN KEY("MemberID") REFERENCES "Members"("MemberID");
ALTER TABLE
    "Members" ADD CONSTRAINT "members_personid_foreign" FOREIGN KEY("PersonID") REFERENCES "Persons"("PersonID");
ALTER TABLE
    "MemberInstructors" ADD CONSTRAINT "memberinstructors_instructorid_foreign" FOREIGN KEY("InstructorID") REFERENCES "Instructors"("InstructorID");
ALTER TABLE
    "Instructors" ADD CONSTRAINT "instructors_personid_foreign" FOREIGN KEY("PersonID") REFERENCES "Persons"("PersonID");
ALTER TABLE
    "Payments" ADD CONSTRAINT "payments_memberid_foreign" FOREIGN KEY("MemberID") REFERENCES "Members"("MemberID");
ALTER TABLE
    "SubscriptionPeriods" ADD CONSTRAINT "subscriptionperiods_paymentid_foreign" FOREIGN KEY("PaymentID") REFERENCES "Payments"("PaymentID");
ALTER TABLE
    "MemberInstructors" ADD CONSTRAINT "memberinstructors_memberid_foreign" FOREIGN KEY("MemberID") REFERENCES "Members"("MemberID");
ALTER TABLE
    "BeltRankTests" ADD CONSTRAINT "beltranktests_paymentid_foreign" FOREIGN KEY("PaymentID") REFERENCES "BeltRanks"("BeltRankID");
ALTER TABLE
    "BeltRankTests" ADD CONSTRAINT "beltranktests_instructorid_foreign" FOREIGN KEY("InstructorID") REFERENCES "Instructors"("InstructorID");
ALTER TABLE
    "BeltRankTests" ADD CONSTRAINT "beltranktests_memberid_foreign" FOREIGN KEY("MemberID") REFERENCES "Members"("MemberID");
ALTER TABLE
    "BeltRankTests" ADD CONSTRAINT "beltranktests_paymentid_foreign" FOREIGN KEY("PaymentID") REFERENCES "Payments"("PaymentID");
ALTER TABLE
    "Members" ADD CONSTRAINT "members_lastbeltrank_foreign" FOREIGN KEY("LastBeltRank") REFERENCES "BeltRanks"("BeltRankID");