# C++ Module 00 - Introduction to C++ Classes

![Language](https://img.shields.io/badge/language-C++98-blue)
![Status](https://img.shields.io/badge/module-00--of--09-informational)

This project is the first in the series of C++ modules in the 42 School Core Curriculum. It serves as an introduction to object-oriented programming in C++, focusing on fundamental topics like classes, member functions, encapsulation, and file structure. No advanced C++ features such as templates, exceptions, or STL containers are used.

---

## 📚 Table of Contents

* [📁 Project Structure](#-project-structure)
* [🧠 Module Overview](#-module-overview)
* [🚀 How to Compile](#-how-to-compile)
* [🔍 Exercises Breakdown](#-exercises-breakdown)

  * [Exercise 00 - megaphone](#exercise-00---megaphone)
  * [Exercise 01 - PhoneBook](#exercise-01---phonebook)
  * [Exercise 02 - Account](#exercise-02---account)
* [🧪 Testing](#-testing)
* [📜 Constraints](#-constraints)
* [📌 Key Concepts](#-key-concepts)
* [📜 License & Credits](#-license--credits)

---

## 📁 Project Structure

```
cpp_module_00/
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/
│   │   ├── Contact.hpp
│   │   └── PhoneBook.hpp
│   └── srcs/
│       ├── Contact.cpp
│       └── PhoneBook.cpp
├── ex02/
    ├── Account.cpp
    ├── Account.hpp
    ├── Makefile
    └── tests.cpp
```

---

## 🧠 Module Overview

This module introduces the following C++ fundamentals:

* `class` and `public` / `private` access specifiers
* Defining member functions inside/outside class definition
* Encapsulation and separation of concerns (headers vs implementation)
* Using static class members and functions
* Working with arrays and strings
* Basic stream I/O (`std::cin`, `std::cout`)
* Compiling multiple source files with a Makefile

---

## 🚀 How to Compile

Each exercise contains a `Makefile`. You can compile each by navigating into its folder and running:

```bash
make
```

For example:

```bash
cd ex01
make
./phonebook
```

---

## 🔍 Exercises Breakdown

### Exercise 00 - megaphone

A simple program that takes command-line arguments and prints them in uppercase.

#### File: `megaphone.cpp`

```cpp
int main(int argc, char *argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++)
            for (int j = 0; argv[i][j]; j++)
                std::cout << (char)std::toupper(argv[i][j]);
        std::cout << std::endl;
    }
    return 0;
}
```

### Exercise 01 - PhoneBook

A classic command-line interface program that stores and displays a maximum of 8 contacts.

Commands:

* `ADD`: Add a new contact
* `SEARCH`: Display a list of contacts and view a contact by index
* `EXIT`: Quit the program

#### Core Classes

* `Contact`: Holds contact details (first name, last name, nickname, number, secret)
* `PhoneBook`: Manages up to 8 contacts, circularly replaces old entries

#### Notable Features

* Uses an array of strings to store user input fields
* Pads or truncates strings to fit in tabular format
* Validates phone number (must be digits only)

#### Code Snippet: Truncated string formatting

```cpp
void print_name(std::string str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::string(10 - str.length(), ' ') << str;
}
```

### Exercise 02 - Account

A simulation of a simple bank account management system.

#### File: `Account.cpp` / `Account.hpp`

Implements an `Account` class with:

* static members tracking total stats
* instance members tracking individual account stats

#### Methods:

* `makeDeposit(int)`
* `makeWithdrawal(int)`
* `displayStatus()`
* `displayAccountsInfos()`
* `_displayTimestamp()` (helper)

#### Code Snippet: Timestamped logging

```cpp
void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm* lt = std::localtime(&now);
    char buf[20];
    if (std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", lt))
        std::cout << buf;
    else
        std::cout << "[00000000_000000] ";
}
```

#### Testing File: `tests.cpp`

* Initializes multiple accounts
* Makes batch deposits and withdrawals
* Demonstrates use of STL containers (`vector`, `pair`, `for_each`)

---

## 🧪 Testing

* Use `make` in each subfolder
* Run `./megaphone`, `./phonebook`, or `./tests`
* Check for memory leaks (e.g., with `valgrind`) for exercises 01 and 02

---

## 📜 Constraints

* Must be compatible with C++98
* No `STL` containers in ex01
* No `namespace`, `exceptions`, `templates`, or `auto`
* Clean Makefiles that handle `all`, `clean`, `fclean`, and `re`
* Adheres to the 42 coding style

---

## 📌 Key Concepts

* Data hiding and access specifiers
* Initializing class members and constructors
* Working with static data across instances
* Simple I/O and validation
* Proper header organization and file structure

---

## 📜 License

This project is part of the 42 School curriculum. Educational use only.
