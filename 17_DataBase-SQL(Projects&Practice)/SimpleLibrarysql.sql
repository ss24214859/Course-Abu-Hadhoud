CREATE TABLE "Books"(
    "IDBook" INT NOT NULL,
    "Title" NVARCHAR(100) NOT NULL,
    "Author" INT NOT NULL,
    "ISBN" NVARCHAR(20) NOT NULL,
    "PublictionDate" DATE NOT NULL,
    "Genre" NVARCHAR(100) NOT NULL,
    "AddtionalDetails" NVARCHAR(200) NULL
);
ALTER TABLE
    "Books" ADD CONSTRAINT "books_idbook_primary" PRIMARY KEY("IDBook");
CREATE TABLE "Authors"(
    "IDAuthor" INT NOT NULL,
    "Name" NVARCHAR(100) NOT NULL
);
ALTER TABLE
    "Authors" ADD CONSTRAINT "authors_idauthor_primary" PRIMARY KEY("IDAuthor");
CREATE TABLE "BookCopes"(
    "IDBookCopy" INT NOT NULL,
    "IDBook" INT NOT NULL,
    "AvailabilityStatus" BIT NOT NULL
);
ALTER TABLE
    "BookCopes" ADD CONSTRAINT "bookcopes_idbookcopy_primary" PRIMARY KEY("IDBookCopy");
CREATE TABLE "Users"(
    "IDUser" INT NOT NULL,
    "Name" NVARCHAR(100) NOT NULL,
    "PhoneNumber" NVARCHAR(100) NOT NULL,
    "Gimal" NVARCHAR(100) NULL,
    "LibraryCardNumber" NVARCHAR(100) NOT NULL
);
ALTER TABLE
    "Users" ADD CONSTRAINT "users_iduser_primary" PRIMARY KEY("IDUser");
CREATE UNIQUE INDEX "users_librarycardnumber_unique" ON
    "Users"("LibraryCardNumber");
CREATE TABLE "BorrowingRecords"(
    "IDBorrow" INT NOT NULL,
    "IDUser" INT NOT NULL,
    "IDBookCopy" INT NOT NULL,
    "BorrowingDate" DATE NOT NULL,
    "DueDate" DATE NOT NULL,
    "ActualReturnDate" DATE NULL
);
ALTER TABLE
    "BorrowingRecords" ADD CONSTRAINT "borrowingrecords_idborrow_primary" PRIMARY KEY("IDBorrow");
CREATE TABLE "Reservations"(
    "IDReservation" INT NOT NULL,
    "IDUser" INT NOT NULL,
    "IDBookCopy" INT NOT NULL,
    "ReservationDate" DATE NOT NULL
);
ALTER TABLE
    "Reservations" ADD CONSTRAINT "reservations_idreservation_primary" PRIMARY KEY("IDReservation");
CREATE TABLE "Fines"(
    "IDFIne" INT NOT NULL,
    "IDUser" INT NOT NULL,
    "IDBottow" INT NOT NULL,
    "LateDays" TINYINT NOT NULL,
    "Amount" INT NOT NULL,
    "PaymentStatus" INT NOT NULL
);
ALTER TABLE
    "Fines" ADD CONSTRAINT "fines_idfine_primary" PRIMARY KEY("IDFIne");
CREATE UNIQUE INDEX "fines_idbottow_unique" ON
    "Fines"("IDBottow");
CREATE TABLE "Settings"(
    "DefualtBorrowDays" INT NOT NULL,
    "DefualtFInePerDay" INT NOT NULL
);
ALTER TABLE
    "Reservations" ADD CONSTRAINT "reservations_idbookcopy_foreign" FOREIGN KEY("IDBookCopy") REFERENCES "BookCopes"("IDBookCopy");
ALTER TABLE
    "Fines" ADD CONSTRAINT "fines_idbottow_foreign" FOREIGN KEY("IDBottow") REFERENCES "BorrowingRecords"("IDBorrow");
ALTER TABLE
    "Authors" ADD CONSTRAINT "authors_name_foreign" FOREIGN KEY("Name") REFERENCES "Books"("Author");
ALTER TABLE
    "Fines" ADD CONSTRAINT "fines_iduser_foreign" FOREIGN KEY("IDUser") REFERENCES "Users"("IDUser");
ALTER TABLE
    "BorrowingRecords" ADD CONSTRAINT "borrowingrecords_iduser_foreign" FOREIGN KEY("IDUser") REFERENCES "Users"("IDUser");
ALTER TABLE
    "Reservations" ADD CONSTRAINT "reservations_iduser_foreign" FOREIGN KEY("IDUser") REFERENCES "Users"("IDUser");
ALTER TABLE
    "BorrowingRecords" ADD CONSTRAINT "borrowingrecords_idbookcopy_foreign" FOREIGN KEY("IDBookCopy") REFERENCES "BookCopes"("IDBookCopy");
ALTER TABLE
    "BookCopes" ADD CONSTRAINT "bookcopes_idbook_foreign" FOREIGN KEY("IDBook") REFERENCES "Books"("IDBook");