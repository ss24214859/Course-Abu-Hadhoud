-- ============================================
-- 🚗 Car Rental Management Database Schema
-- Author: Mohamed 
-- ============================================

CREATE TABLE Persons (
    PersonID       INT PRIMARY KEY,                -- 🔑
    Name           NVARCHAR(100) NOT NULL,
    ContactINFO    NVARCHAR(200) Not NULL
);

CREATE TABLE Customers (
    CustomerID              INT PRIMARY KEY,        -- 🔑
    PersonID                INT NOT NULL,
    DriverLicenseNumber     NVARCHAR(50) UNIQUE  not NULL,
    FOREIGN KEY (PersonID) REFERENCES Persons(PersonID)
);

CREATE TABLE VehicleCategory (
    VehicleCategoryID   INT PRIMARY KEY,            -- 🔑
    VehicleCategory     NVARCHAR(100) UNIQUE  NOT NULL
);

CREATE TABLE FuelType (
    FuelTypeID   INT PRIMARY KEY,                   -- 🔑
    FuelType     NVARCHAR(50) UNIQUE NOT NULL       -- ❄
);

CREATE TABLE Vehicles (
    VehicleID           INT PRIMARY KEY,            -- 🔑
    Make                NVARCHAR(100) NOT NULL,
    Model               NVARCHAR(100) NOT NULL,
    Year                DATE NOT NULL,
    Mileage             NVARCHAR(50) not NULL,
    FuelTypeID          INT NOT NULL,
    RentalRates         NVARCHAR(100) NULL,
    PlateNumber         NVARCHAR(50)  NOT NULL,
    VehicleCategoryID   INT NOT NULL,
    IsAvailableForRent  BIT NOT NULL,

    FOREIGN KEY (FuelTypeID) REFERENCES FuelType(FuelTypeID),
    FOREIGN KEY (VehicleCategoryID) REFERENCES VehicleCategory(VehicleCategoryID)
);

CREATE TABLE Maintenance (
    MaintenanceID    INT PRIMARY KEY,              -- 🔑
    VehicleID        INT NOT NULL,
    Description      NVARCHAR(200) Not NULL,
    MaintenanceDate  DATE NOT NULL,
    Cost             INT NOT NULL,

    FOREIGN KEY (VehicleID) REFERENCES Vehicles(VehicleID)
);

CREATE TABLE RentalBooking (
    BookingID             INT PRIMARY KEY,         -- 🔑
    CustomerID            INT NOT NULL,
    VehicleID             INT NOT NULL,
    StartDate             DATE NOT NULL,
    EndDate               DATE NOT NULL,
    PickupLocation        NVARCHAR(100) NOT NULL,
    DropOffLocation       NVARCHAR(100) not NULL,
    InitialRentalDays     INT NOT NULL,
    InitialTotalDueAmount INT NOT NULL,
    InitialVehicleCheck   NVARCHAR(150) not NULL,

    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID),
    FOREIGN KEY (VehicleID) REFERENCES Vehicles(VehicleID)
);

CREATE TABLE VehicleReturns (
    VehicleReturnID             INT PRIMARY KEY,          -- 🔑
    ActualReturnDate     DATE NOT NULL,
    ActualRentalDays     INT NOT NULL,
    FinalCheckNotes      NVARCHAR(200) not NULL,
    AdditionalCharges    NVARCHAR(200) not NULL,
    Milage               INT NOT NULL,
    ConsumedMileage      INT NOT NULL,
    ActualTotalDueAmount INT NOT NULL
);

CREATE TABLE RentalTransactions (
    TransactionID          INT PRIMARY KEY,      -- 🔑
    CustomerID             INT NOT NULL,
    BookingID              INT NOT NULL UNIQUE,
    VehicleReturnID        INT NULL UNIQUE,
    PaymentDetails         NVARCHAR(200) not NULL,
    PaidInitialTotalAmount INT not NULL,
    ActualTotalDueAmount   INT NULL,
    RemainingAmount        INT NULL,
    RefundAmount           INT NULL,
    TransactionDate        DATE NOT NULL,
    UpdatedTransactionDate DATE NULL,

    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID),
    FOREIGN KEY (BookingID)  REFERENCES RentalBooking(BookingID),
    FOREIGN KEY (VehicleReturnID)   REFERENCES VehicleReturns(VehicleReturnID)
);
