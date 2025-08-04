# C++ Module 08 - Templated Containers, Iterators, and Algorithms

![Language](https://img.shields.io/badge/language-C++98-blue)
![Status](https://img.shields.io/badge/progress-Completed-brightgreen)

This module introduces the power of C++ templates and the STL (Standard Template Library). You will explore key STL components like containers, iterators, and algorithms, with an emphasis on using them correctly and efficiently. For the first time, you are encouraged (and expected) to leverage the STL in your solutions.

---

## 📂 Table of Contents

* [📚 Project Structure](#-project-structure)
* [📓 Exercise Breakdown](#-exercise-breakdown)

  * [🔍 ex00 - easyfind](#-ex00---easyfind)
  * [⚖️ ex01 - Span](#-ex01---span)
  * [🤯 ex02 - MutantStack](#-ex02---mutantstack)
* [📊 STL Containers & Algorithms Used](#-stl-containers--algorithms-used)
* [🧪 Build & Run](#-build--run)
* [🔹 Key Concepts Reinforced](#-key-concepts-reinforced)
* [🎓 42 School Constraints](#-42-school-constraints)
* [📌 License](#-license)

---

## 📂 Project Structure

```bash
cpp_module_08/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   └── easyfind.hpp
│
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/
│   │   └── Span.hpp
│   └── srcs/
│       └── Span.cpp
│
├── ex02/
    ├── Makefile
    ├── main.cpp
    └── MutantStack.hpp
```

---

## 📓 Exercise Breakdown

### 🔍 ex00 - easyfind

Implements a generic function template `easyfind` that searches for an integer in any container of integers.

* **Functionality:**

  * Accepts any container (`vector`, `list`, `deque`, etc.) and a target integer.
  * Returns an iterator to the first matching element.
  * Throws a custom `NotFoundException` if not found.

* **Header:** `easyfind.hpp`

```cpp
template <typename T>
typename T::iterator easyfind(T &container, int num);
```

* **Use Case:**

```cpp
std::vector<int> vec = {1, 2, 3};
auto it = easyfind(vec, 2);  // returns iterator to 2
```

---

### ⚖️ ex01 - Span

Implements a `Span` class that:

* Stores up to `N` integers.

* Can calculate:

  * The **shortest span** (min difference between any two numbers)
  * The **longest span** (max difference between smallest and largest numbers)

* **Class:** `Span`

* **Header:** `Span.hpp`

* **Implementation:** `Span.cpp`

#### Features:

* `addNumber(int)`
* `shortestSpan()` / `longestSpan()`
* Overload assignment and copy constructor
* Custom exceptions:

  * `VectorIsFullException`
  * `NeedMoreElementsException`

#### Bonus:

* Bulk addition using iterator ranges.

```cpp
Span sp(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl; // 2
std::cout << sp.longestSpan() << std::endl; // 14
```

---

### 🤯 ex02 - MutantStack

STL's `std::stack` does not support iteration. This exercise adapts it into an iterable class.

* **Class:** `MutantStack`
* **Header:** `MutantStack.hpp`
* **Base:** Inherits from `std::stack<T>`

#### Features:

* Provides iterator access:

  * `begin()` / `end()`
  * `rbegin()` / `rend()`
  * `const_` versions of all
* Uses `std::stack<T>::container_type::iterator` as base
* All standard stack operations supported (push, pop, top)

```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();

for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    std::cout << *it << std::endl;
```

---

## 📊 STL Containers & Algorithms Used

### Containers

* **std::vector**: Used in `Span` to dynamically store and manage integers.
* **std::list / std::deque**: Accepted by `easyfind()` template (can be tested with these).
* **std::stack**: Inherited in `MutantStack`, used for stack operations with extended iterator support.

### Algorithms

* **std::find**: Used in `easyfind()` to search for a number in a generic container.
* **std::sort**: Used in `Span` to sort a copy of the vector for shortest span calculation.
* **std::min\_element / std::max\_element**: Used in `Span` to calculate longest span.

These STL components greatly simplify implementation, improve code readability, and showcase idiomatic C++ usage.

---

## 🧪 Build & Run

```bash
cd ex01
make
./span
```

Test edge cases:

* Empty spans
* Single-element spans
* Adding beyond capacity
* Missing values for `easyfind`

---

## 🔹 Key Concepts Reinforced

* Template programming
* STL containers: `vector`, `list`, `deque`, `stack`
* Iterators: forward, reverse, const
* Exception handling
* Generic programming (templated functions and classes)
* Algorithm usage: `std::find`, `std::min_element`, `std::max_element`, `std::sort`

---

## 🎓 42 School Constraints

* C++98 standard
* Orthodox Canonical Form for all classes
* Allowed to use:

  * STL containers (for Module 08+ only)
  * STL algorithms (`<algorithm>`)
* Forbidden:

  * `printf`, `malloc`, `free`, `using namespace`, `friend`

---

## 📌 License

This project is part of the 42 School curriculum and intended for educational use only.
