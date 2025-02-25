
# Library Management System

## Overview

This project is a simple **Library Management System** implemented in C++ using object-oriented programming (OOP) principles. The system allows users to manage books by adding, removing, searching, and displaying available books. It also utilizes **file handling** to persist data and **STL containers (vector, map)** to manage book records efficiently.

## Features

-   Add a new book to the library.
    
-   Remove a book using its ID.
    
-   Search for books by title or author (case-insensitive).
    
-   Display all available books.
    
-   File handling for persistent storage.
    
-   Error handling and input validation.
    
-   Prevents duplicate book IDs.
    

### Bonus Features

-   User management with borrowing and returning functionalities.
    
-   A simple login system for users.
    
-   Optimized search functionality using maps.
    

## Technologies Used

-   **Programming Language:** C++
    
-   **STL Containers:**  `vector`, `map`
    
-   **File Handling:**  `fstream`
    
-   **Exception Handling:**  `try-catch` blocks for robust error management
    

## Class Definitions

### 1. Book Class

Manages individual book details such as ID, title, and author.

```
class Book {
private:
    int id;
    std::string title;
    std::string author;
public:
    Book(int, std::string, std::string);
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
};
```

### 2. Library Class

Handles operations on books, including adding, removing, searching, and displaying books.

```
class Library {
private:
    std::vector<Book> books;
    void saveToFile();
    void loadFromFile();
public:
    Library();
    void addBook(int, std::string, std::string);
    void removeBook(int);
    void searchBook(std::string) const;
    void displayBooks() const;
};
```

### 3. User Class (Bonus Feature)

Handles user-related actions such as borrowing and returning books.

```
class User {
private:
    std::string username;
    std::vector<int> borrowedBooks;
public:
    void borrowBook(int);
    void returnBook(int);
};
```

## How to Run the Program

### Compilation

1.  Open a terminal or command prompt.
    
2.  Navigate to the directory containing the source code.
    
3.  Compile the program using:
    
    ```
    g++ -o library_management main.cpp
    ```
    
4.  Run the executable:
    
    ```
    ./library_management
    ```
    

### Usage

-   The program will display a **menu-driven interface**.
    
-   Follow the on-screen instructions to interact with the system.
    
-   Data is **saved automatically** using file handling.
    

## Error Handling

-   Invalid inputs are handled using exception handling.
    
-   The system ensures that books cannot be duplicated based on ID.
    
-   If a book is not found while searching or removing, an appropriate message is displayed.
    
-   File handling errors are managed to prevent crashes.
    

## Reflection on Problem-Solving Approach

-   **OOP Design:** Ensured modularity by separating book management and user management.
    
-   **STL Containers:** Used `vector` for book storage and `map` for optimizing searches.
    
-   **File Handling:** Ensured persistent storage of books.
    
-   **Robustness:** Implemented exception handling to manage invalid inputs and edge cases.
    
-   **Improved Search:** Implemented case-insensitive title search.
    

## Future Improvements

-   Implement a **GUI-based interface** using Qt or a web-based interface.
    
-   Add **database support** for enhanced storage.
    
-   Improve **user authentication** with encrypted passwords.
    

## Author

Developed by **Abhyanand**

----------

**Note:** This project was implemented independently without external references to assess problem-solving and coding skills.
