# Employees Management System

## 📌 Project Overview

Employees Management System is a Windows Forms desktop application developed to manage employees information and attendance operations.

The system provides an easy way for organizations to store employee data, track daily attendance, and manage attendance statuses efficiently.

This project was built as part of practical training while studying desktop application development.

---

## 🏗 System Architecture

The project follows a **3-Tier Architecture**:

1. **Presentation Layer**

   * Windows Forms UI
   * Handles user interaction

2. **Business Logic Layer (BLL)**

   * Processes system rules
   * Validates data

3. **Data Access Layer (DAL)**

   * Communicates with SQL Server
   * Executes queries & stored procedures

---

## 🛠 Technologies Used

* C#
* .NET Framework – Windows Forms
* SQL Server
* ADO.NET
* Visual Studio

---

## ✨ System Features

### 👨‍💼 Employees Management

* Add new employees
* Edit employees data
* Delete employees
* View employees list
* Search employees

### 📅 Attendance Management

* Record daily attendance
* Assign attendance status
* Track attendance history
* Filter by date

### 📊 Data Handling

* Organized database structure
* Relational tables
* Secure data storage

---

## 🗄 Database Design

Main Tables:

* **Employees**

  * EmployeeID (PK)
  * FirstName
  * LastName
  * Phone
  * HireDate

* **Attendance**

  * AttendanceID (PK)
  * EmployeeID (FK)
  * StatusID (FK)
  * DayDate

* **AttendanceStatus**

  * StatusID (PK)
  * StatusName

---

## ⚙️ Installation & Setup

1️⃣ Clone the repository

```bash
git clone https://github.com/ss24214859/Course-Abu-Hadhoud.git
```

2️⃣ Open the solution file in Visual Studio.

3️⃣ Setup Database

* Open SQL Server Management Studio.
* Create a new database.
* Run the provided SQL script.

4️⃣ Update Connection String

Edit:

```
App.config
```

Add your SQL Server connection string.

5️⃣ Run the project.

---

## 📷 Screenshots

Add system screenshots here:

* Employees Form
* Add/Edit Employee
* Attendance Screen

Example:

```md
## 📷 Screenshots

### 👨‍💼 Employees List

![Employees1](Screenshots/Employees1.png)

![Employees2](Screenshots/Employees2.png)

---

### ➕ Add Employee

![Add](Screenshots/ِAdd.png)

---

### ✏️ Edit Employee

![Edit](Screenshots/Edit.png)

---

### 📅 Attendance Screen

![Attendance](Screenshots/Attendance.png)

### 📅 Statistics Screen

![Statistics](Screenshots/Statistics.png)
```

---

## 🚀 Future Enhancements

* User Authentication System
* Role & Permissions
* Reports & Analytics
* Export to Excel / PDF
* Dashboard UI

---

## 👨‍💻 Author

**Mohamed Shaaban**

* GitHub: [https://github.com/ss24214859](https://github.com/ss24214859)

---

## 📜 License

This project is for learning purposes and training.
