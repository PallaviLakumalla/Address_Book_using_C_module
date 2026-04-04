# 📇 Address Book Application (C Language)

## 📌 Overview

This project is a menu-driven Address Book application developed in the C programming language. It is designed to manage contact information efficiently through a simple command-line interface.

The application allows users to perform essential operations such as adding, viewing, searching, updating, and deleting contact details. It uses file handling techniques to ensure that all data is stored persistently in a CSV file, enabling data retention even after program execution.



![design](https://github.com/user-attachments/assets/e93f3ac1-1756-45a8-9247-2343dc0156a0)


## 🎯 Objective

The main objective of this project is to understand and implement:

* File handling in C
* Structured programming
* Data storage and retrieval
* Menu-driven application design


## ✨ Key Features

### ➤ Add Contact

* Allows users to add new contact details such as name, phone number, and other fields.
* Data is stored in a CSV file for persistence.

### ➤ View Contacts

* Displays all saved contacts in a structured format.
* Helps in quick overview of stored data.

### ➤ Search Contact

* Search functionality based on:

  * Name
  * Phone number
* Efficient retrieval of specific contact details.

### ➤ Edit Contact

* Enables modification of existing contact information.
* Updates are reflected in the CSV file.

### ➤ Delete Contact

* Allows removal of unwanted or outdated contacts.
* Ensures database remains clean and updated.


## 💾 Data Storage

* Contacts are stored in a file named `database.csv`.
* CSV format is used for simplicity and easy readability.
* Ensures persistent storage across multiple runs.


## 🛠️ Technologies Used

* **Programming Language:** C
* **File Handling:** CSV-based storage
* **Compiler:** GCC
* **Platform:** Linux / Ubuntu


## 📂 Project Structure

Address_book/
│
├── main.c              # Entry point of the application
├── addressbook.c      # Implementation of core functionalities
├── addressbook.h      # Function declarations and structures
├── database.csv       # Stores contact information
└── README.md          # Project documentation


## ⚙️ How It Works

1. User runs the program.
2. A menu is displayed with multiple options.
3. Based on user input, the corresponding operation is performed.
4. Data is read from or written to the CSV file.
5. Changes are saved permanently.


## 🚀 How to Run

1. Open terminal in project directory
2. Compile the program:

   ```
   gcc main.c addressbook.c -o addressbook
   ```
3. Run the application:

   ```
   ./addressbook
   ```


## 💡 Applications

* Personal contact management system
* Beginner-level database handling project
* Learning file operations in C
* CLI-based utility applications


## 📌 Conclusion

This project demonstrates how file handling and structured programming concepts can be used to build a simple yet effective contact management system. It provides a strong foundation for developing more advanced database-driven applications.
