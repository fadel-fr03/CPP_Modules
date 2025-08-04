# C++ Module 07 - Templates and Generic Programming

![Language](https://img.shields.io/badge/language-C++98-blue)
![Status](https://img.shields.io/badge/progress-Completed-brightgreen)

This module introduces generic programming in C++ using templates. You’ll learn how to design type-agnostic code, making use of function templates, template classes, and template specialization. This marks an important step toward modern C++ design patterns and reusable components.

---

## 📂 Table of Contents

* [📁 Project Structure](#-project-structure)
* [📘 Exercise Breakdown](#-exercise-breakdown)

  * [🧮 ex00 - Function Templates (whatever)](#-ex00---function-templates-whatever)
  * [🔁 ex01 - Function Template Iteration (iter)](#-ex01---function-template-iteration-iter)
  * [📦 ex02 - Template Array Class](#-ex02---template-array-class)
* [🧪 Build & Run](#-build--run)
* [🔹 Key Concepts Reinforced](#-key-concepts-reinforced)
* [🎓 42 School Constraints](#-42-school-constraints)
* [📜 License](#-license)

---

## 📁 Project Structure

```
cpp_module_07/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   └── whatever.hpp         # Template functions for swap, min, max
│
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   └── iter.hpp             # Template function iter to apply functions on arrays
│
├── ex02/
    ├── Makefile
    ├── main.cpp
    └── Array.hpp            # Template class Array<T> with bounds checking
```

---

## 📘 Exercise Breakdown

### 🧮 ex00 - Function Templates (whatever)

Implements three generic template functions:

* `swap(T &a, T &b)`
* `min(const T &a, const T &b)`
* `max(const T &a, const T &b)`

**Constraints:**

* Must work for both built-in types (int, float, etc.) and user-defined types.
* Must be fully templated in header file `whatever.hpp`.

**Objective:**

* Understand syntax and power of function templates.
* Practice writing generic functions usable across types.

---

### 🔁 ex01 - Function Template Iteration (iter)

Implements a function template:

```cpp
template <typename T>
void iter(T *array, size_t length, void (*func)(T &));
```

**Behavior:**

* Applies the given function to each element of the array.
* Supports arrays of both built-in and custom types.

**Example Use:**

```cpp
void printInt(int &x) { std::cout << x << std::endl; }
int arr[5] = {1, 2, 3, 4, 5};
iter(arr, 5, printInt);
```

**Objective:**

* Practice higher-order programming using function pointers and templates.
* Understand template parameter deduction and reference passing.

---

### 📦 ex02 - Template Array Class

Implements a generic class `Array<T>` mimicking dynamic arrays with bounds checking.

**Required Functionality:**

* Constructors:

  * Default
  * Parametrized with size `n`
  * Copy constructor
* Operator overloads:

  * Assignment
  * Subscript operator `operator[]` (with bounds checking)
* Method:

  * `size()`

**Constraints:**

* Bounds violations must throw a standard `std::exception`.
* Template implementation must reside in `Array.hpp`.

**Objective:**

* Apply templates in class design.
* Understand memory management and deep copy principles with templates.

---

## 🧪 Build & Run

Each exercise includes a Makefile. Example for ex02:

```bash
cd ex02
make
./array
```

**Test thoroughly:**

* Exception throwing for invalid access
* Proper copy semantics
* Template instantiation with multiple types (int, std::string, etc.)

---

## 🔹 Key Concepts Reinforced

* Function templates and class templates
* Template instantiation and compilation model
* Template specialization constraints
* Use of function pointers in templates
* Bounds checking and exception safety
* Header-only design (entire implementation in `.hpp`)

---

## 🎓 42 School Constraints

* Must comply with C++98 (no variadic templates, auto, etc.)
* Template definitions and implementations must be in the header file
* Orthodox Canonical Form for template classes
* No use of STL containers or algorithms

---

## 📜 License

This project is part of the 42 School curriculum and is intended for educational use only.
