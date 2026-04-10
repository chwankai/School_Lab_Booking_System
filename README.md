# 🧪 School Lab Booking System

## 📖 Project Description

FIST: Lab Booking System is a C-based console application that allows users to register, log in, and manage laboratory room reservations.

The system is designed to simulate a real-world lab booking process in a university environment, supporting booking, viewing, editing, searching, and deleting reservations.

All data is stored using binary file handling in C, making it lightweight and easy to run without any external database.

---

## 🏢 Supported Buildings & Labs

### CDP Building (Block B)

* MBMR 2021
* MBMR 2022

### FIST Building

* MNBR 2005 Application Lab
* MNBR 2006 Database Lab
* MNBR 2007 Software Engineering Lab
* MNBR 3007 Molecular Lab

---

## 🔐 Authentication System

The system includes a simple file-based user authentication system.

### Features:

* User Registration
* Login System
* Password Confirmation
* Stored in `login_account.txt`

---

## 🧾 Features

### 👤 User Features

* Register and login account
* Book a lab
* View all reservations
* Search reservation by day
* Edit number of students in a booking
* Cancel reservation
* View lab location
* Exit system

---

## ⚙️ System Functionalities

### 📌 Booking System

* Select building and lab
* Choose day of reservation
* Select time slot
* Enter number of students
* Save booking into file

### 📌 Manage Reservations

* Display all bookings
* Search bookings by day
* Edit booking details
* Delete booking records

### 📌 Utility Functions

* Lab location lookup
* Assign lab name automatically
* Assign day name automatically

---

## 💾 File Handling

The system uses binary file storage:

* `login_account.txt` → Stores user accounts (struct account)
* `information.txt` → Stores booking records (struct booking)
* `temp.txt` / `tempp.txt` → Temporary files for delete/edit operations

---

## ▶️ How to Run

### Compile:

```bash
gcc School_Lab_Booking_System.c -o lab_booking
```

### Run:

```bash
./lab_booking
```

---

## 📌 Program Flow

1. Register or Login
2. Access Main Menu
3. Perform operations:

   * Book lab
   * View reservations
   * Search by day
   * Edit or delete booking
   * View lab locations
4. Exit system

---
