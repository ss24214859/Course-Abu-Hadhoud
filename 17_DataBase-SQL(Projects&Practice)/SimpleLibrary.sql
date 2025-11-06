Create Table Authors(
	AuthorID int Not NULL,
	Name nvarchar(100) Not NUll,
);

---
Create Table Books
(
	BookID int ,
	Title nvarchar(100) not Null,
	AuthorID int Not Null,
	ISBN nvarchar(20) Not NUll,
	PublictionDate date not NUll,
	Genre nvarchar(100) not Null,
	AddtionalDetails nvarchar(200),
	Primary key (BookID)
);
Alter Table Books
Add foreign Key (AuthorID) References Authors(AuthorID);

Create Table BookCopies(
	BookCopyID int ,
	BookID int Not NULL,
	AvailabilityStatus bit NOt Null,
	primary key (BookCopyID),
);

Alter Table BookCopies
Add foreign Key (BookID) References Books(BookID);

Create Table BorrowingRecords
(
	BorrowingRecordID int primary Key,
	UserID int Not Null,
	BookCopyID int not null,
	BorrowingDate date not Null,
	DueDate date  not Null,
	ActualReturnDate date ,
);
Alter Table BorrowingRecords
Add foreign Key (BookCopyID) References BookCopies(BookCopyID);
Alter Table BorrowingRecords
Add foreign Key (UserID) References Users(UserID);
create Table Fines
(
	FineID int primary Key,
	UserID int not Null,
	BorrowingRecordID int not Null Unique ,
	LateDays int ,
	Amount int Not Null,
	PaymentStatus int Not null
);
Alter Table Fines
Add foreign Key (BorrowingRecordID) References BorrowingRecords(BorrowingRecordID);
Alter Table Fines
Add foreign Key (UserID) References Users(UserID);

create Table Reservations
(
	ReservationID int primary key,
	UserID int Not Null,
	BookCopyID int not Null,
	ReservationDate Date Not Null
);
Alter Table Reservations
Add foreign Key (BookCopyID) References BookCopies(BookCopyID);
Alter Table Reservations
Add foreign Key (UserID) References Users(UserID);

Create Table Users
(
	UserID int PRimary KEy,
	Name nvarchar(100) not NUll,
	PhoneNumber nvarchar(100) not null,
	Gimal nvarchar(100) ,
	LibraryCardNumber nvarchar(100) Unique,

);

Create Table  Settings
(
	DefualtBorrowDays int, 
	DefualtFinePerDay int

);


SELECT Users.UserID, Users.Name, Users.LibraryCardNumber, BorrowingRecords.BorrowingDate, Books.Title, Books.BookID
FROM     Authors INNER JOIN
                  Books ON Authors.AuthorID = Books.AuthorID INNER JOIN
                  BookCopies ON Books.BookID = BookCopies.BookID INNER JOIN
                  BorrowingRecords ON BookCopies.BookCopyID = BorrowingRecords.BookCopyID INNER JOIN
                  Fines ON BorrowingRecords.BorrowingRecordID = Fines.BorrowingRecordID INNER JOIN
                  Reservations ON BookCopies.BookCopyID = Reservations.BookCopyID AND BookCopies.BookCopyID = Reservations.BookCopyID AND BookCopies.BookCopyID = Reservations.BookCopyID INNER JOIN
                  Users ON BorrowingRecords.UserID = Users.UserID AND BorrowingRecords.UserID = Users.UserID AND BorrowingRecords.UserID = Users.UserID AND BorrowingRecords.UserID = Users.UserID AND Fines.UserID = Users.UserID AND 
                  Reservations.UserID = Users.UserID CROSS JOIN
                  Settings
