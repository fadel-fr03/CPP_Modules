# C++ Module 06 - Casting and Runtime Type Identification

This module dives into type casting, serialization, and dynamic type identification in C++98. You’ll learn how to safely convert between data types, store and restore raw memory representations, and identify derived types at runtime. These exercises focus on low-level operations and RTTI (Run-Time Type Information), solidifying your understanding of type systems and memory representation in object-oriented C++.

---

## 📂 Table of Contents

* [📁 Project Structure](#-project-structure)
* [📘 Exercise Breakdown](#-exercise-breakdown)

  * [🔄 ex00 - ScalarConverter](#-ex00---scalarconverter)
  * [🧬 ex01 - Serialization](#-ex01---serialization)
  * [🔍 ex02 - Dynamic Casting](#-ex02---dynamic-casting)
* [🧪 Build & Run](#-build--run)
* [🧠 Key Concepts Reinforced](#-key-concepts-reinforced)
* [🎓 42 School Constraints](#-42-school-constraints)
* [📜 License](#-license)

---

## 📁 Project Structure

```
cpp_module_06/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/ScalarConverter.hpp
│   └── srcs/ScalarConverter.cpp
│
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/Data.hpp
│   ├── incs/Serializer.hpp
│   ├── srcs/Data.cpp
│   └── srcs/Serializer.cpp
│
├── ex02/
    ├── Makefile
    ├── main.cpp
    ├── incs/Base.hpp  # abstract base
    ├── incs/A.hpp     # derived
    ├── incs/B.hpp     # derived
    ├── incs/C.hpp     # derived
    └── srcs/Base.cpp, Utils.cpp
```

---

## 📘 Exercise Breakdown

### 🔄 ex00 - ScalarConverter

Implements a static class `ScalarConverter` that converts a string input into multiple scalar types: `char`, `int`, `float`, and `double`.

* **Main Functionality**:

  * Detect and convert strings like "42", "a", "42.0f", or "nan" into valid types
  * Display conversions, handling edge cases (e.g., overflow, impossible conversions)

* **Required Output Format**:

  ```
  char: Non displayable
  int: 42
  float: 42.0f
  double: 42.0
  ```

* **Edge Handling**:

  * Detect overflows and underflows for each type
  * Handle special float values like `nan`, `+inf`, `-inf`

* **Design Notes**:

  * Static methods only, no instantiation allowed
  * Robust input parsing and validation is key

### 🧬 ex01 - Serialization

Introduces `reinterpret_cast` to convert raw pointers to integers and back.

* **Classes**:

  * `Data`: a basic struct with some members
  * `Serializer`: contains static methods:

    ```cpp
    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);
    ```

* **Concepts**:

  * Raw memory representation of pointers
  * `uintptr_t` from `<cstdint>` ensures integer large enough to hold a pointer
  * Useful for low-level memory manipulation and storing pointers in non-type-safe locations (e.g., disk, network, etc.)

### 🔍 ex02 - Dynamic Casting

Implements an abstract base class `Base`, and three derived classes: `A`, `B`, `C`.

* **Goal**:

  * Randomly generate a derived class instance
  * Use `dynamic_cast` to determine the actual type at runtime

* **Two Functions Required**:

  ```cpp
  void identify(Base* p);
  void identify(Base& p);
  ```

* **Differences**:

  * Pointer version uses `nullptr` check
  * Reference version uses `try`/`catch` on bad\_cast

* **Demonstrates**:

  * Runtime Type Identification (RTTI)
  * The power and safety of `dynamic_cast`
  * Exceptions in casting references

* **Use Case**:

  * Reflective code where type is unknown but polymorphic behavior is required

---

## 🧪 Build & Run

Each subdirectory has its own Makefile.

```bash
cd ex00
make
./convert "42.0"

cd ../ex01
make
./serialize

cd ../ex02
make
./identify
```

Test various edge cases like `nan`, overflows, null pointers, and invalid input.

---

## 🧠 Key Concepts Reinforced

* `reinterpret_cast` vs `static_cast` vs `dynamic_cast`
* Serialization of raw pointers using `uintptr_t`
* RTTI and runtime type identification using `dynamic_cast`
* Exception handling in reference casting
* Input validation and string parsing logic
* Static class utility pattern

---

## 🎓 42 School Constraints

* Must follow Orthodox Canonical Form (Rule of 4) unless otherwise stated
* No use of C++11 or modern features
* No `friend` or `using namespace` allowed
* No STL containers (e.g., `vector`, `map`, `list`) or `<algorithm>`
* Only `<string>`, `<iostream>`, and `<sstream>` used extensively

---

## 📜 License

This project is part of the 42 School curriculum and intended for educational purposes only.
