# C++ Module 03 - Inheritance and Multiple Inheritance

![Language](https://img.shields.io/badge/language-C++98-blue)
![Status](https://img.shields.io/badge/progress-Completed-brightgreen)

This module introduces class inheritance in C++, covering single and multiple inheritance, construction and destruction order, method overriding, and ambiguity resolution. Students will work with a family of classes that progressively expand on the behavior of a base class, `ClapTrap`, building a hierarchy that ends with the diamond-shaped inheritance pattern in `DiamondTrap`.

---

## 📑 Table of Contents

* [📂 Project Structure](#-project-structure)
* [📘 Exercise Breakdown](#-exercise-breakdown)

  * [🛡️ ex00 - ClapTrap Class](#-ex00---claptrap-class)
  * [🛡️ ex01 - ScavTrap Class (Single Inheritance)](#-ex01---scavtrap-class-single-inheritance)
  * [🔨 ex02 - FragTrap Class (Another Single Inheritance)](#-ex02---fragtrap-class-another-single-inheritance)
  * [💎 ex03 - DiamondTrap Class (Multiple Inheritance)](#-ex03---diamondtrap-class-multiple-inheritance)
* [🧪 Build & Run](#-build--run)
* [✅ Attribute Comparison Table](#-attribute-comparison-table)
* [📌 Key Concepts Reinforced](#-key-concepts-reinforced)
* [🎓 42 School Constraints](#-42-school-constraints)
* [📜 License](#-license)

---

## 📂 Project Structure

```
cpp_module_03/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/
│   │   └── ClapTrap.hpp
│   └── srcs/
│       └── ClapTrap.cpp
│
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/
│   │   ├── ClapTrap.hpp
│   │   └── ScavTrap.hpp
│   └── srcs/
│       ├── ClapTrap.cpp
│       └── ScavTrap.cpp
│
├── ex02/
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/
│   │   ├── ClapTrap.hpp
│   │   ├── ScavTrap.hpp
│   │   └── FragTrap.hpp
│   └── srcs/
│       ├── ClapTrap.cpp
│       ├── ScavTrap.cpp
│       └── FragTrap.cpp
│
├── ex03/
    ├── Makefile
    ├── main.cpp
    ├── incs/
    │   ├── ClapTrap.hpp
    │   ├── ScavTrap.hpp
    │   ├── FragTrap.hpp
    │   └── DiamondTrap.hpp
    └── srcs/
        ├── ClapTrap.cpp
        ├── ScavTrap.cpp
        ├── FragTrap.cpp
        └── DiamondTrap.cpp
```

Each exercise builds on the previous by extending and testing functionality of the class hierarchy.

---

## 📘 Exercise Breakdown

### 🛡️ ex00 - ClapTrap Class

This exercise introduces the base `ClapTrap` class and lays the foundation for inheritance.

* **Attributes (private)**:

  * `std::string _name;`
  * `unsigned int _hitPoints = 10;`
  * `unsigned int _energyPoints = 10;`
  * `unsigned int _attackDamage = 0;`

* **Public Methods**:

  * `ClapTrap(std::string name);`
  * `void attack(const std::string &target);`
  * `void takeDamage(unsigned int amount);`
  * `void beRepaired(unsigned int amount);`

* **Constructor & Destructor Messages**:

  * Each constructor and destructor logs a message for debug and test visibility.

* **Behavior Notes**:

  * Attacks and repairs cost 1 energy point.
  * Cannot act if HP or energy is 0.
  * Informative messages reflect each action and state change.

---

### 🛡️ ex01 - ScavTrap Class (Single Inheritance)

`ScavTrap` inherits from `ClapTrap` and modifies its attributes and behavior.

* **Modified Attributes**:

  * `hitPoints = 100`
  * `energyPoints = 50`
  * `attackDamage = 20`

* **New Method**:

  * `void guardGate();` – announces that ScavTrap is in Gate Keeper mode.

* **Overridden Behavior**:

  * Constructor, destructor, and `attack()` print ScavTrap-specific messages.

* **Construction Flow**:

  * Base `ClapTrap` constructor is called first.
  * Destruction occurs in reverse (ScavTrap → ClapTrap).

---

### 🔨 ex02 - FragTrap Class (Another Single Inheritance)

Similar to ScavTrap but with different behavior and an additional method.

* **Modified Attributes**:

  * `hitPoints = 100`
  * `energyPoints = 100`
  * `attackDamage = 30`

* **New Method**:

  * `void highFivesGuys();` – prints a friendly high five request.

* **Construction Flow**:

  * Same as ScavTrap, showing proper constructor chaining.

---

### 💎 ex03 - DiamondTrap Class (Multiple Inheritance)

`DiamondTrap` inherits from both `ScavTrap` and `FragTrap`.

* **Complex Inheritance Structure**:

  * Uses virtual inheritance to prevent multiple `ClapTrap` copies.

* **Own Attribute**:

  * `std::string _name;` – separate from `ClapTrap::_name`.
  * `ClapTrap::_name` initialized as `_name + "_clap_name"`

* **Inherited Attributes**:

  * `hitPoints` from `FragTrap`
  * `energyPoints` from `ScavTrap`
  * `attackDamage` from `FragTrap`

* **New Method**:

  * `void whoAmI();` – prints both `_name` and `ClapTrap::_name`

* **Overrides**:

  * Uses `ScavTrap::attack()`

---

## 🧪 Build & Run

Each exercise directory contains its own `Makefile`.

```bash
cd ex02
make
./a.out
```

Recommended tests:

* Constructor/destructor chain validation
* Overridden method behavior
* Attribute values per class
* Special methods like `whoAmI()`

---

## ✅ Attribute Comparison Table

| Class       | Hit Points | Energy Points | Attack Damage | Special Method    |
| ----------- | ---------- | ------------- | ------------- | ----------------- |
| ClapTrap    | 10         | 10            | 0             | -                 |
| ScavTrap    | 100        | 50            | 20            | `guardGate()`     |
| FragTrap    | 100        | 100           | 30            | `highFivesGuys()` |
| DiamondTrap | 100 (F)    | 50 (S)        | 30 (F)        | `whoAmI()`        |

**(F) FragTrap, (S) ScavTrap** denote inherited attribute source.

---

## 📌 Key Concepts Reinforced

* 🌳 Single and Multiple Inheritance
* 🧱 Canonical Form (constructor, copy constructor, assignment, destructor)
* 🔁 Method Overriding and Overloading
* 🔎 Diamond Inheritance and Ambiguity Resolution
* 🔧 Proper constructor chaining and memory safety
* 🧠 Class relationships and hierarchy design

---

## 🎓 42 School Constraints

* Must follow Orthodox Canonical Form
* No use of STL containers or `<algorithm>`
* No `friend` or `using namespace` statements
* Strictly C++98 compatible

---

## 📜 License

This project is part of the 42 School curriculum and intended for educational use only.
