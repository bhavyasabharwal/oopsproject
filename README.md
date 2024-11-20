# Student Grading System

This is a simple **C++ project** implementing an **Object-Oriented Programming (OOP)** approach to manage student details and calculate their grades. The project demonstrates the use of OOP concepts such as **classes**, **inheritance**, **polymorphism**, and **encapsulation**, along with modern C++ features like **smart pointers** and **templates**.

---

## Features

- **Encapsulation**: Separates data (student details) from logic (grade calculation).
- **Inheritance**: Uses an abstract `Person` base class and a derived `Student` class.
- **Polymorphism**: Abstract base class enforces a common interface for displaying data.
- **Dynamic Memory Management**: Uses `std::shared_ptr` for managing objects.
- **Error Handling**: Ensures robust execution using exceptions.
- **Template Function**: Displays a list of objects generically.

---

## Code Overview

### Key Components
1. **Classes**:
   - `Person`: Abstract base class representing a generic individual.
   - `Student`: Derived class that extends `Person` with specific student details.

2. **Functions**:
   - `addMarks`: Adds marks for a specific subject and updates the grade.
   - `displayInfo`: Displays student information and their grade.
   - `calculateGrade`: Computes grades based on marks using a predefined scale.

3. **Utilities**:
   - `utils::printLine`: Prints a line of repeated characters for formatting.
   - Template function `displayList`: Displays details of all objects in a collection.

---

## Requirements

- **Compiler**: Any C++ compiler supporting C++11 or later (e.g., GCC, Clang, MSVC).
- **Development Environment**: VS Code (recommended) or any IDE of your choice.

---

## Setup and Usage

### 1. Clone the Repository
```bash
git clone <repository-url>
cd student-grading-system
