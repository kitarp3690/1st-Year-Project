# 1st-Year-Project (C++)

This repository contains a Bank Management System simulation implemented in C++. The system caters to two types of users:

1. Admin (Bank staff)
2. User (Bank customer)

## Admin Features:
- Creating user accounts
- Searching accounts
- Depositing money
- Withdrawing money
- Deleting accounts

Note: The file `admin.txt` contains the admin's ID and password for login (default is `id=admin`, `pw=admin`). Additional admins can be added by appending `admin_name admin_password` entries to this file.

## User Features:
- Viewing personal information
- Checking transaction history
- Changing password

Note: When a user account is created by an admin, the username and password will be as follows:
- Username: User's Mobile Number (98.....)
- Password: User's First Name

