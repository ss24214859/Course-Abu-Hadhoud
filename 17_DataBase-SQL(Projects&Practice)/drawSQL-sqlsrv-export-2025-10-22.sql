CREATE TABLE "ProductCategory" (
    "CategoryID" INT NOT NULL PRIMARY KEY,
    "CategoryName" NVARCHAR(100) NOT NULL UNIQUE
);

CREATE TABLE "ProductCatalog" (
    "ProductID" INT NOT NULL PRIMARY KEY,
    "ProductName" NVARCHAR(100) NOT NULL,
    "Description" NVARCHAR(200) NOT NULL,
    "Price" INT NOT NULL,
    "QuantityInStock" INT NOT NULL,
    "CategoryID" INT NOT NULL,
    FOREIGN KEY ("CategoryID") REFERENCES "ProductCategory"("CategoryID")
);

CREATE TABLE "Customers" (
    "CustomerID" INT NOT NULL PRIMARY KEY,
    "Name" NVARCHAR(50) NOT NULL,
    "Phone" NVARCHAR(20) NOT NULL,
    "Email" NVARCHAR(200) NOT NULL,
    "Address" NVARCHAR(200) NOT NULL,
    "Username" NVARCHAR(100) NOT NULL UNIQUE,
    "Password" NVARCHAR(200) NOT NULL
);

CREATE TABLE "Orders" (
    "OrderID" INT NOT NULL PRIMARY KEY,
    "CustomerID" INT NOT NULL,
    "OrderDate" DATETIME NOT NULL,
    "TotalAmount" DECIMAL(10, 2) NOT NULL,
    "Status" SMALLINT NOT NULL,
    FOREIGN KEY ("CustomerID") REFERENCES "Customers"("CustomerID")
);

CREATE TABLE "OrderItems" (
    "OrderID" INT NOT NULL,
    "ProductID" INT NOT NULL,
    "Quantity" INT NOT NULL,
    "Price" DECIMAL(10, 2) NOT NULL,
    "TotalItemsPrice" AS ("Quantity" * "Price") PERSISTED, -- محسوبة تلقائيًا
    PRIMARY KEY ("OrderID", "ProductID"),
    FOREIGN KEY ("OrderID") REFERENCES "Orders"("OrderID"),
    FOREIGN KEY ("ProductID") REFERENCES "ProductCatalog"("ProductID")
);

CREATE TABLE "Payments" (
    "TransactionID" INT NOT NULL PRIMARY KEY,
    "OrderID" INT NOT NULL UNIQUE,
    "Amount" DECIMAL(10, 2) NOT NULL,
    "PaymentMethod" NVARCHAR(50) NOT NULL,
    "Timestamp" TIMESTAMP NOT NULL,
    FOREIGN KEY ("OrderID") REFERENCES "Orders"("OrderID")
);

CREATE TABLE "Shippings" (
    "ShippingID" INT NOT NULL PRIMARY KEY,
    "OrderID" INT NOT NULL UNIQUE,
    "CarrierName" NVARCHAR(200) NOT NULL,
    "TrackingNumber" NVARCHAR(50) UNIQUE,
    "ShippingStatus" BIT NOT NULL,
    "EstimatedDeliveryDate" DATE NOT NULL,
    "ActualDeliveryDate" DATE NULL,
    "Notes" NVARCHAR(200) NULL,
    FOREIGN KEY ("OrderID") REFERENCES "Orders"("OrderID")
);

CREATE TABLE "Reviews" (
    "ReviewID" INT NOT NULL PRIMARY KEY,
    "ProductID" INT NOT NULL,
    "CustomerID" INT NOT NULL,
    "ReviewText" NVARCHAR(200) NOT NULL,
    "Rating" DECIMAL(8, 2) NULL,
    "ReviewDate" DATETIME NOT NULL,
    FOREIGN KEY ("CustomerID") REFERENCES "Customers"("CustomerID"),
    FOREIGN KEY ("ProductID") REFERENCES "ProductCatalog"("ProductID")
);

CREATE TABLE "Images" (
    "ImageID" INT NOT NULL PRIMARY KEY,
    "ProductID" INT NOT NULL,
    "ImageURL" NVARCHAR(400) NOT NULL,
    "ImageOrder" SMALLINT NOT NULL,
    FOREIGN KEY ("ProductID") REFERENCES "ProductCatalog"("ProductID")
);
