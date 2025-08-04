# C++ Module 09 - STL Algorithms, Parsing, RPN & Ford-Johnson Merge-Insert Sort

![Language](https://img.shields.io/badge/language-C++98-blue)
![Status](https://img.shields.io/badge/progress-Completed-brightgreen)

This module leverages the full power of the Standard Template Library (STL), placing an emphasis on algorithmic efficiency, parsing robustness, and real-world problem-solving. Through three exercises, you'll dive deep into containers, iterators, exception handling, input validation, and one of the most optimal comparison-based sorting algorithms — Ford-Johnson Merge-Insert Sort.

---

## 📂 Table of Contents

* [📚 Project Structure](#-project-structure)
* [📓 Exercise Breakdown](#-exercise-breakdown)

  * [🔍 ex00 - BitcoinExchange](#-ex00---bitcoinexchange)
  * [➗ ex01 - Reverse Polish Notation](#-ex01---reverse-polish-notation)
  * [📊 ex02 - PmergeMe](#-ex02---pmergeme)
* [🧪 Build & Run](#-build--run)
* [🔹 STL Containers & Algorithms](#-stl-containers--algorithms)
* [💡 Advanced Concepts](#-advanced-concepts)
* [🎓 42 School Constraints](#-42-school-constraints)
* [📌 License](#-license)

---

## 📚 Project Structure

```bash
cpp_module_09/
├── ex00/
│   ├── main.cpp
│   ├── srcs/
│   │   └── BitcoinExchange.cpp
│   └── incs/
│       └── BitcoinExchange.hpp
│
├── ex01/
│   ├── main.cpp
│   ├── srcs/
│   │   └── RPN.cpp
│   └── incs/
│       └── RPN.hpp
│
├── ex02/
│   ├── main.cpp
│   ├── srcs/
│   │   ├── PmergeMe.cpp
│   │   └── Timer.cpp
│   └── incs/
│       ├── PmergeMe.hpp
│       └── Timer.hpp
```

---

## 📓 Exercise Breakdown

### 🔍 ex00 - BitcoinExchange

Simulates a mini cryptocurrency exchange by reading a database of historical Bitcoin prices and computing exchange values for user-provided data.

* **Input Files:**

  * `data.csv`: Historical Bitcoin prices (format: `YYYY-MM-DD,price`)
  * `input.txt`: User values (format: `date | value`, must include a header line)

Example of valid `input.txt`:

```
date | value
2011-01-03 | 3
2011-01-09 | 1
```

* **Parsing:**

  * Validates date format (YYYY-MM-DD), leap years, and logical values
  * Checks floating point validity and range (0 to 1000)
* **Functionality:**

  * Maps dates to exchange rates
  * Searches the closest previous available date using `std::map::lower_bound`
  * Calculates value × price

**STL Used:** `std::map`

```bash
./btc input.txt
```

---

### ➗ ex01 - Reverse Polish Notation

Evaluates mathematical expressions written in postfix notation using a stack-based approach.

* **Input:** A single string representing a space-separated postfix expression
* **Operators Supported:** `+`, `-`, `*`, `/`
* **Error Handling:**

  * Invalid tokens
  * Stack underflow
  * Divide by zero

**Core Idea:** Uses a LIFO stack to evaluate operations as they appear.

**STL Used:** `std::stack`

```bash
./RPN "3 5 + 7 *"
# Output: 56
```

---

### 📊 ex02 - PmergeMe

This exercise implements a high-performance, comparison-optimized Ford-Johnson merge-insert sort using both `std::vector` and `std::deque`.

* **Key Requirement:**

  * Ford-Johnson must be used
  * For 21-element input, must not exceed **66 comparisons**

#### ✅ Features

* Parses and validates integer sequence input from CLI
* Rejects:

  * Duplicates
  * Invalid or non-positive integers
* Sorts using:

  * `std::vector`
  * `std::deque`
* Measures:

  * Elapsed CPU time in microseconds
  * Comparison count

#### 💡 Ford-Johnson Merge-Insert Sort

* Builds pairs (larger first)
* Recursively sorts larger elements
* Constructs optimal insertion sequence using **Jacobsthal numbers**
* Binary inserts the smaller (pend) elements using calculated bounds
* Specialized logic for arrays of 5 or fewer elements to minimize comparisons

#### 📈 Output Example:

```bash
$ ./PmergeMe 9 3 5 1 7 4 2 8 6
Sorting sequence using the std::vector container:
Before: 9 3 5 1 7 4 2 8 6
After:  1 2 3 4 5 6 7 8 9
Time to process a range of 9 elements with std::vector : 99 us
Comparisons used: 18
✓ Sequence is correctly sorted!

Sorting sequence using the std::deque container:
Before: 9 3 5 1 7 4 2 8 6
After:  1 2 3 4 5 6 7 8 9
Time to process a range of 9 elements with std::deque : 70 us
Comparisons used: 18
✓ Sequence is correctly sorted!
```

**STL Used:**

* Containers: `std::vector`, `std::deque`, `std::pair`
* Utilities: `std::stringstream`, `std::clock`, `std::exception`, `std::min`, `std::swap`

---

## 🧪 Build & Run

```bash
# ex00
make -C ex00 && ./btc input.txt

# ex01
make -C ex01 && ./RPN "3 4 +"

# ex02
make -C ex02 && ./PmergeMe 1 3 2 8 5 4 6 9
```

---

## 🔹 STL Containers & Algorithms

### Containers:

* `std::map` — Efficiently sorted associative container, used in ex00 for date lookup.
* `std::stack` — LIFO container used in ex01.
* `std::vector` — Contiguous memory, random access, used in ex02.
* `std::deque` — Double-ended queue, allows efficient push/pop from both ends.

### Algorithms/Utilities:

* `std::find` — Used for search operations
* `std::swap` — Used extensively in small case sort optimization
* `std::min` — Bounds logic for binary insert
* `std::clock` — Timing CPU usage in microseconds
* `std::getline`, `std::stringstream` — Stream-based parsing

---

## 💡 Advanced Concepts

### 🧠 Ford-Johnson (Merge-Insert Sort)

* Comparison-optimal sorting algorithm (O(n log n) comparisons)
* Not widely used in production due to complex implementation
* Still relevant in theoretical computer science and academic benchmarks

### 📈 Jacobsthal Numbers

* Sequence used to optimize insertion order: `0, 1, 1, 3, 5, 11, 21, ...`
* Ensures optimal binary insertion strategy with minimal comparisons

### ⚖️ Comparison Counting

* Each binary comparison is counted explicitly
* Small cases (n <= 5) have hardcoded optimal sort logic
* Maintains ≤66 comparisons for 21-element input

---

## 🎓 42 School Constraints

* Follows C++98 standard strictly
* No use of `printf`, `malloc`, `new`, or `using namespace std`
* Only allowed STL: containers and algorithms (module 08+)
* Must implement Orthodox Canonical Form (OCF):

  * Default constructor
  * Copy constructor
  * Assignment operator
  * Destructor

---

## 📌 License

This project is part of the 42 School curriculum and intended for educational purposes only. Fork, share, and study responsibly.
