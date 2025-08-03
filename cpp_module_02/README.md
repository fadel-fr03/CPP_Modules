# C++ Module 02 - Fixed-point Arithmetic and Operator Overloading

![Language](https://img.shields.io/badge/language-C++98-blue)
![Status](https://img.shields.io/badge/progress-Completed-brightgreen)

This module continues the C++ journey with a deep dive into ad-hoc polymorphism (i.e., operator overloading), fixed-point number implementation, and rigorous application of the **Orthodox Canonical Form** in C++ class design.

All exercises revolve around building a reusable `Fixed` class to represent fixed-point numbers, and using it in various scenarios including mathematical operations and 2D geometry.

---

## 📂 Project Structure

```
cpp_module_02/
├── ex00/                # Canonical class form and raw fixed-point storage
│   ├── main.cpp
│   ├── srcs/Fixed.cpp
│   └── incs/Fixed.hpp
│
├── ex01/                # Fixed-point to float/int conversions and stream insertion
│   ├── main.cpp
│   ├── srcs/Fixed.cpp
│   └── incs/Fixed.hpp
│
├── ex02/                # Operator overloading, comparison, arithmetic, increment/decrement
│   ├── main.cpp
│   ├── srcs/Fixed.cpp
│   └── incs/Fixed.hpp
│
├── ex03/                # 2D point geometry and BSP algorithm
│   ├── main.cpp
│   ├── srcs/
│   │   ├── Fixed.cpp
│   │   ├── Point.cpp
│   │   └── bsp.cpp
│   └── incs/
│       ├── Fixed.hpp
│       └── Point.hpp
```

---

## 📘 Exercise Breakdown

### 🧱 ex00 - My First Class in Orthodox Canonical Form

* Implements the `Fixed` class with the Orthodox Canonical Form:

  * Default constructor
  * Copy constructor
  * Copy assignment operator
  * Destructor
* Stores fixed-point value as an integer (`_value`) with a constant fractional bits (`_fractionalBits = 8`)
* Adds getter and setter:

  ```cpp
  int getRawBits(void) const;
  void setRawBits(int const raw);
  ```

🧪 **Tested using**:

```cpp
Fixed a;
Fixed b(a);
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
```

### 💡 ex01 - Towards a More Useful Fixed Class

* Adds:

  * Constructor from `int`
  * Constructor from `float`
  * Conversion to `int` and `float`
  * Overloaded `<<` operator to stream fixed-point as float

```cpp
float toFloat(void) const;
int toInt(void) const;
```

🧪 **Tested with**:

```cpp
Fixed const b(10);
Fixed const c(42.42f);
std::cout << "c is " << c << std::endl;
std::cout << "c as int is " << c.toInt() << std::endl;
```

### ➕ ex02 - Operator Overloading & Static Min/Max

* Overloads:

  * Arithmetic: `+`, `-`, `*`, `/`
  * Comparison: `>`, `<`, `>=`, `<=`, `==`, `!=`
  * Increment/Decrement: `++`, `--` (both pre and post)

* Adds static utilities:

  ```cpp
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
  ```

🧪 **Tested using**:

```cpp
Fixed const b(Fixed(5.05f) * Fixed(2));
std::cout << ++a << std::endl;
std::cout << Fixed::max(a, b) << std::endl;
```

### 📐 ex03 - BSP (Binary Space Partitioning)

* Adds a new class `Point` in Orthodox Canonical Form:

  * Attributes: `Fixed const x`, `Fixed const y`
  * Constructor from floats: `Point(float x, float y)`

* Implements function:

  ```cpp
  bool bsp(Point const a, Point const b, Point const c, Point const point);
  ```

  This function determines whether `point` lies **inside** triangle `(a, b, c)` using a cross-product based algorithm.

* Uses area method or barycentric coordinate logic.

🧪 **Example test**:

```cpp
Point a(0, 0), b(5, 0), c(0, 5);
Point p(2, 2);
std::cout << bsp(a, b, c, p) << std::endl;  // should print 1 (true)
```

---

## 📚 Concepts Covered

* 📌 **Fixed-point arithmetic** implementation
* 📘 **Orthodox Canonical Form** (Rule of 4):

  * Proper object lifecycle management
* ➕ **Operator Overloading**:

  * Arithmetic, comparison, increment/decrement
* 🛠️ **Static methods** in classes
* 🧮 **Geometric computations** in 2D using user-defined types

---

## 🧪 Compilation & Execution

Each exercise contains a `Makefile` with targets such as `all`, `clean`, `fclean`, and `re`. To compile:

```bash
cd ex01
make
./a.out
```

---

## 🧼 Code Standards

* Written in **C++98**
* Complies with 42 rules: No `using namespace`, no STL, no friend, and strict separation of header and implementation.
* Operator overloads are implemented carefully to avoid memory leaks or side effects.

---

## 📜 License

This project is part of the 42 School curriculum. Educational use only.
