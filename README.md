# 🚗 Vehicle Management System (C++)

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![OOP](https://img.shields.io/badge/Architecture-OOP-success?style=for-the-badge)
![Memory Management](https://img.shields.io/badge/Memory-Smart_Pointers-blueviolet?style=for-the-badge)

## 📌 Project Overview
A console-based Vehicle Management System built in C++. This project is not just about adding and deleting records; it serves as a practical demonstration of **Clean Architecture**, **Robust Memory Management**, and the **Zero Trust** principle for user inputs.

## 🏗️ Core Engineering Principles Applied

* **Separation of Concerns:** The system architecture strictly separates interfaces from implementations.
    * `Models/Vehicle.h`: Acts as the blueprint (Interface).
    * `Models/Vehicle.cpp`: Contains the operational logic (Implementation).
    * `main.cpp`: Serves solely as the entry point and dependency injector.
* **Smart Memory Management:** Complete elimination of raw pointers (`new`/`delete`). The system uses `<memory>` and `std::unique_ptr` to ensure zero memory leaks during object lifecycle.
* **Polymorphism & OOP:** Utilizes abstract base classes (`Car`) and derived classes (`Taxi`, `Bus`) to handle dynamic vehicle types in a single `std::vector`.
* **Zero Trust (Fail-Fast Logic):**
* * Implementation of **Guard Clauses** (e.g., checking `if(list.empty()) return;` before execution).
    * Strict input validation using `cin.fail()` and `try-catch` blocks to prevent system crashes from invalid user inputs.
* **Persistent Storage (File I/O):** Features state-saving capabilities allowing data to be written to and read from a `.txt` database securely.

## 📁 Project Structure
├── Models/ 
│ ├── Vehicle.h (Class Definitions & Prototypes) 
│ └── Vehicle.cpp (Methods Implementation) 
└── main.cpp (Entry Point & Menu Logic)
