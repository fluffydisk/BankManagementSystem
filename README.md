# 💻 Bank Management System (C++)

This project is a Bank Management System developed in C++ that simulates basic bank account functionalities. It allows users to create accounts, sign in, transfer money, and view logs of all transactions and account activities. The system features a simple console-based interface and is designed to help understand core concepts of C++ such as object-oriented programming (OOP), file handling, and account security with logging.
🎮 Features

    User Registration: Create a new bank account by providing a unique ID, name, surname, and balance.
    Sign In: Log into your account using a unique ID and password.
    Send Money: Transfer funds between accounts securely.
    Account Details: View detailed information about your account, including balance and logs.
    Transaction Logs: View all activities logged by the system, including balance changes, transfers, and sign-ins.
    Account Deletion: Delete an existing account and remove it from the system.
    Error Handling: Basic input validation for options, IDs, and balances.

🛠️ Classes and Structure

The system is designed using three main classes:
1. BankAccount

This class represents an individual bank account. It contains user details such as name, ID, password, and balance. It also handles functionalities like:

    Changing balance (increase or decrease)
    Sending money to another account
    Displaying account details and account logs

2. Log

This class is responsible for managing and recording logs of all account-related activities. Each action is timestamped and stored for later retrieval.

    Create logs for events such as account creation, money transfers, or balance updates.
    Print logs for either a specific account or for the entire system.
    Find logs by their unique IDs.

3. Game

This is the main class that manages the flow of the system. It contains:

    Menus for signing in, signing up, and performing operations once logged in.
    Account management functionality (create, delete, view details, send money).
    Log handling for recording important actions.

📋 Menu Options
Main Menu:

    Sign In: Log into your account using ID and password.
    Sign Up: Create a new account.
    Print System Logs: View logs of all actions performed in the system.
    Exit: End the program.

Logged-In Menu:

    See Account Details: View your ID, name, surname, balance, and password.
    Send Money: Transfer funds to another registered account.
    Delete Account: Permanently remove your account from the system.
    Print Account Logs: View all the logs associated with your account.
    Sign Out: Log out of the current account.
    Exit: End the program.

🧑‍💻 Technologies Used

    C++: Core programming language used for the system.
    Object-Oriented Programming (OOP): To manage different functionalities using classes.
    Basic File I/O: For logging and managing data persistently (although not yet implemented in the current version).

🌱 Future Improvements

    Persistent Data Storage: Add file handling to save and load account data and logs between sessions.
    Encryption: Improve password security by hashing and encrypting user credentials.
    Input Handling: Improve input handling that corrupts when given a data type other than the excepted one.
    Multi-User Support: Allow multiple users to interact with the system simultaneously.

📄 License

This project is open-source and available under the MIT License.
