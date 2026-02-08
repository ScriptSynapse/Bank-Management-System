# Bank Management System (C)

A simple, menu-driven **Bank Management System** written in **C**.
The project demonstrates core C programming concepts such as structures, functions, arrays, and switch-case based menus, with a focus on clarity and correctness.

It includes **secure PIN-based login** with a **three-attempt lock mechanism** and supports **multiple bank accounts** during runtime.

---

## Overview

This project simulates basic banking operations in a console environment.
Each user account is protected by a PIN and can perform common operations after successful authentication.

The codebase is intentionally kept lightweight and readable, making it suitable for learning, review, and extension.

---

## Features

* Multiple account support using arrays of structures
* Account creation with PIN setup
* Secure login using account number and PIN
* Automatic lock after **three incorrect PIN attempts**
* Deposit funds
* Withdraw funds with balance validation
* Balance inquiry
* Logout functionality
* Menu-driven interface using `switch case`

---

## Built With

* **Language:** C
* **Compiler:** GCC (or any standard C compiler)

### Core Concepts Used

* Structures and arrays of structures
* Functions and modular programming
* Conditional logic and loops
* Switch-case control flow

---

## Getting Started

### Prerequisites

* A C compiler (GCC recommended)
* Terminal or command prompt

### Compilation

```bash
gcc bank.c -o bank
```

### Execution

```bash
./bank
```

---

## Usage

1. Create a new bank account by providing:

    * Account number
    * Account holder name
    * 4-digit PIN
    * Initial balance

2. Log in using your account number and PIN

3. Perform banking operations from the account menu

4. The system locks login access after three incorrect PIN attempts

---

## Project Structure

```
bank-management-system/
├── bank.c
└── README.md
```

---

## Design Notes

* Data is stored **in memory only**
* No external libraries are used
* The lock system is session-based
* The program prioritizes simplicity over real-world banking complexity

---

## Limitations

* No persistent storage (data resets on program exit)
* No encryption or hashing for PIN storage
* No concurrency or multi-user session handling

---

## Roadmap

Potential future enhancements include:

* File handling for persistent data storage
* PIN hashing for improved security
* Change PIN functionality
* Admin-level account management
* Improved input validation and error handling

---

## Author

**Paulson Alex Fernandes**

---

## License

This project is released for **educational and learning purposes**.
You are free to use, modify, and extend it.


