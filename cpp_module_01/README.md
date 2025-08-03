# C++ Module 01 - Memory, References, and File Streams

![Language](https://img.shields.io/badge/language-C++98-blue)
![Status](https://img.shields.io/badge/module-01_completed-brightgreen)

This module dives deeper into fundamental C++ concepts like memory allocation, references, object lifetime, and input/output operations using streams. Each exercise is crafted to reinforce the differences between heap and stack memory, object instantiation, and object-oriented principles such as encapsulation and function pointers.

---

## 📁 Project Structure

```
cpp_module_01/
├── ex00/        # Stack vs Heap, object creation
├── ex01/        # Dynamic array of objects (zombie horde)
├── ex02/        # Pointers vs References
├── ex03/        # Class composition with Weapon (HumanA/HumanB)
├── ex04/        # File I/O and string replacement
├── ex05/        # Using function pointers (Harl 1.0)
├── ex06/        # Control flow and switch-case logic (Harl 2.0)
```

---

## 📚 Exercise Overview

### 🧠 ex00 - Stack vs Heap (Zombie)

* Implements:

  * `Zombie` class
  * `newZombie(std::string)` (heap allocation)
  * `randomChump(std::string)` (stack allocation)
* Objective: Understand object lifetime, stack vs heap, and manual memory management.

**Highlights:**

* When a zombie is created with `newZombie()`, it must be manually deleted using `delete`.
* `randomChump()` creates the zombie on the stack and is destroyed automatically after the function returns.

```cpp
Zombie* newZombie(std::string name);
void randomChump(std::string name);
```

---

### 🧟‍♂️ ex01 - Zombie Horde

* Implements:

  * Function `zombieHorde(int N, std::string name)` that returns a dynamically allocated array of zombies.
* Objective: Practice allocating arrays on the heap and initializing each object.

```cpp
Zombie* horde = zombieHorde(N, "Zombo");
```

---

### 🧭 ex02 - Pointers and References

* Demonstrates the difference between:

  * A pointer to a string
  * A reference to the same string
* Objective: Understand how references and pointers behave in terms of memory addressing.

```cpp
std::string* stringPTR = &str;
std::string& stringREF = str;
```

---

### 🧱 ex03 - HumanA and HumanB

* Implements two classes:

  * `HumanA`: takes a reference to `Weapon` during construction
  * `HumanB`: can be constructed without a weapon and assigned one later
* Objective: Understand the use of references vs pointers in class composition.

```cpp
HumanA bob("Bob", club);
HumanB jim("Jim");
jim.setWeapon(club);
```

---

### 📝 ex04 - Replace in File

* Implements a small utility that:

  * Takes a filename and two strings as input
  * Replaces all occurrences of the first string with the second in the file
  * Outputs the result to `<filename>.replace`
* Objective: Practice file I/O with `ifstream` and `ofstream`, string manipulation.

```bash
./replace input.txt "old" "new"
```

---

### 📣 ex05 - Harl 1.0

* Implements a `Harl` class with member functions:

  * `debug()`, `info()`, `warning()`, `error()`
* Uses a function pointer array to map strings to methods.
* Objective: Master dynamic function dispatch without `if`/`else` or `switch`.

```cpp
void (Harl::*handlers[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
```

---

### 🚨 ex06 - Harl 2.0 (Switch-case Behavior)

* Implements the same levels as ex05, but uses a `switch`-like cascading behavior:

  * If the user enters a valid level, all levels from that point downward are printed.
* Objective: Control flow and fallthrough logic using `switch`-like structure.

---

## 🧪 How to Build and Run

Each exercise contains a Makefile. To build an exercise:

```bash
cd ex04
make
./replace input.txt old new
```

---

## ✅ Key Concepts Reinforced

* Memory allocation: `new`, `delete`, stack vs heap
* Pointers vs references
* File I/O using `ifstream` and `ofstream`
* Function pointers and dispatch tables
* Input validation and basic error handling
* Class composition using reference vs pointer members

---

## 📌 Notes

* All code adheres strictly to C++98.
* No use of STL containers beyond basic string manipulation.
* All dynamic allocations are paired with proper deallocation.
* Input validation is considered in user-facing programs.

---

## 🎓 42 School Constraints Respected

* No usage of STL containers like `vector`, `map`, `set` etc.
* No exceptions used.
* No use of namespaces or modern C++ features (C++11 and beyond).

---

## 📬 License

This project is part of the 42 School curriculum and intended for educational use only.
