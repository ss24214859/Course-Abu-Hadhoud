CREATE TABLE "Persons"(
    "PersonID" INT NOT NULL Primary Key,
    "Name" NVARCHAR(100) NOT NULL,
    "Address" NVARCHAR(200) NOT NULL,
    "ContactINFO" NVARCHAR(100) NOT NULL
);

CREATE TABLE "BeltRanks"(
    "BeltRankID" INT NOT NULL Primary Key,
    "RankName" NVARCHAR(100) NOT NULL Unique,
    "TestFees" INT NOT NULL
);

CREATE TABLE "Members"(
    "MemberID" INT NOT NULL Primary Key,
    "PersonID" INT NULl Unique Foreign Key References Persons(PersonID),
    "EmergencyINFO" NVARCHAR(100) NOT NULL,
    "LastBeltRank" INT NULL Foreign Key References BeltRanks(BeltRankID),
    "IsActive" BIT NOT NULL
);
---

CREATE TABLE "Instructors"(
    "InstructorID" INT NOT NULL Primary Key,
    "PersonID" INT NOT NULL unique Foreign Key References Persons(PersonID),
    "Qualifications" NVARCHAR(100) NOT NULL
);

-----------
CREATE TABLE "Payments"(
    "PaymentID" INT NOT NULL Primary Key,
    "Amount" INT NOT NULL,
    "Date" DATE NOT NULL,
    "status" NVARCHAR(100) NOT NULL,
    "MemberID" INT NOT NULL  Foreign Key References Members(MemberID)
);

CREATE TABLE "SubscriptionPeriods"(
    "SubscriptionPeriodID" INT NOT NULL  Primary Key,
    "StartDate" DATE NOT NULL,
    "EndDate" DATE NOT NULL,
    "Fees" INT NOT NULL,
    "PaymentID" INT NOT NULL Unique Foreign Key References Payments(PaymentID),
    "MemberID" INT NOT NULL Foreign Key References Members(MemberID),
);



CREATE TABLE "BeltRankTests"(
    "BeltRankTestID" INT NOT NULL Primary Key,
    "TestDate" DATE NOT NULL,
    "Result" NVARCHAR(100) NOT NULL,
    "BeltRankID" INT NOT NULL Foreign Key References BeltRanks(BeltRankID),
    "PaymentID" INT NOT NULL Unique  Foreign Key References Payments(PaymentID),
    "MemberID" INT NOT NULL  Foreign Key References Members(MemberID),
    "InstructorID" INT NOT NULL  Foreign Key References Instructors(InstructorID)
);



CREATE TABLE "MemberInstructors"(
    "AssignmentID" INT NOT NULL Primary Key,
    "MemberID" INT NOT NULL Foreign Key References Members(MemberID),
    "InstructorID" INT NOT NULL Foreign Key References Instructors(InstructorID),
    "AssignDate" DATE NOT NULL,
    "EndDate" DATE NOT NULL
);



SELECT Members.MemberID, Persons.Name, Members.LastBeltRank
FROM     BeltRanks INNER JOIN
                  BeltRankTests ON BeltRanks.BeltRankID = BeltRankTests.BeltRankID INNER JOIN
                  Instructors ON BeltRankTests.InstructorID = Instructors.InstructorID INNER JOIN
                  MemberInstructors ON Instructors.InstructorID = MemberInstructors.InstructorID INNER JOIN
                  Members ON BeltRanks.BeltRankID = Members.LastBeltRank AND BeltRankTests.MemberID = Members.MemberID AND MemberInstructors.MemberID = Members.MemberID INNER JOIN
                  Payments ON BeltRankTests.PaymentID = Payments.PaymentID AND Members.MemberID = Payments.MemberID INNER JOIN
                  Persons ON Instructors.PersonID = Persons.PersonID AND Members.PersonID = Persons.PersonID INNER JOIN
                  SubscriptionPeriods ON Members.MemberID = SubscriptionPeriods.MemberID AND Payments.PaymentID = SubscriptionPeriods.PaymentID