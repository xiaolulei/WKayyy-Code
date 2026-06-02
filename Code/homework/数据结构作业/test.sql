CREATE DATABASE BookDB
GO

USE BookDB
GO

CREATE TABLE BookClass
(
classNo CHAR(4) PRIMARY KEY,
className VARCHAR(20) NOT NULL
)

CREATE TABLE Publisher
(
publisherNo CHAR(4) PRIMARY KEY,
publisherName VARCHAR(20) NOT NULL
)

CREATE TABLE Book
(
bookNo CHAR(10) PRIMARY KEY,
classNo CHAR(4) NOT NULL FOREIGN KEY REFERENCES BookClass(classNo),
bookName VARCHAR(40) NOT NULL,
authorName VARCHAR(8),
publisherNo CHAR(4) NOT NULL FOREIGN KEY REFERENCES Publisher(publisherNo),
price DECIMAL(7,2) CHECK(price>=0),
publishingDate DATE,
shopDate DATE,
shopNum INT NOT NULL DEFAULT 0 CHECK(shopNum>=0)
)

CREATE TABLE Reader
(
readerNo CHAR(8) PRIMARY KEY,
readerName VARCHAR(8) NOT NULL,
sex CHAR(2) CHECK(sex IN('男','女')),
identitycard CHAR(18) UNIQUE,
workUnit VARCHAR(50),
borrowCount INT NOT NULL DEFAULT 10 CHECK(borrowCount>=0)
)

CREATE TABLE Borrow
(
readerNo CHAR(8) NOT NULL,
bookNo CHAR(10) NOT NULL,
borrowDate DATE NOT NULL,
shouldDate DATE NOT NULL,
returnDate DATE,
PRIMARY KEY(readerNo,bookNo,borrowDate),
FOREIGN KEY(readerNo) REFERENCES Reader(readerNo),
FOREIGN KEY(bookNo) REFERENCES Book(bookNo),
CHECK(shouldDate>=borrowDate)
)
