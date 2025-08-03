# C++ Module 04 - Subtype Polymorphism, Abstract Classes, and Interfaces

![Language](https://img.shields.io/badge/language-C++98-blue)
![Status](https://img.shields.io/badge/progress-Completed-brightgreen)

This module deepens your understanding of polymorphism in C++ by introducing abstract classes, subtype polymorphism, and interfaces. You'll build on previous modules by leveraging dynamic binding, virtual destructors, and interfaces to build reusable and extensible components.

---

## 📑 Table of Contents

* [📂 Project Structure](#-project-structure)
* [📘 Exercise Breakdown](#-exercise-breakdown)

  * [🔁 ex00 - Polymorphism](#-ex00---polymorphism)
  * [🧠 ex01 - Brain & Deep Copy](#-ex01---brain--deep-copy)
  * [📵 ex02 - Abstract Class](#-ex02---abstract-class)
  * [🧪 ex03 - Interface & Materia System](#-ex03---interface--materia-system)
* [🧪 Build & Run](#-build--run)
* [📌 Key Concepts Reinforced](#-key-concepts-reinforced)
* [🎓 42 School Constraints](#-42-school-constraints)
* [📜 License](#-license)

---

## 📂 Project Structure

```
cpp_module_04/
├── ex00/                     # Base polymorphism with Animal, Dog, Cat
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/
│   │   ├── Animal.hpp
│   │   ├── Cat.hpp
│   │   ├── Dog.hpp
│   │   ├── WrongAnimal.hpp
│   │   └── WrongCat.hpp
│   └── srcs/
│       ├── Animal.cpp
│       ├── Cat.cpp
│       ├── Dog.cpp
│       ├── WrongAnimal.cpp
│       └── WrongCat.cpp
├── ex01/                     # Introduces Brain class and deep copy
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/ (same as ex00 + Brain.hpp)
│   └── srcs/ (same as ex00 + Brain.cpp)
├── ex02/                     # Abstract Animal base class
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/ (same as ex01)
│   └── srcs/ (same as ex01)
├── ex03/                     # Interfaces, AMateria, ICharacter, MateriaSource
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/
│   │   ├── AMateria.hpp
│   │   ├── Character.hpp
│   │   ├── Cure.hpp
│   │   ├── ICharacter.hpp
│   │   ├── Ice.hpp
│   │   ├── IMateriaSource.hpp
│   │   └── MateriaSource.hpp
│   └── srcs/
│       ├── AMateria.cpp
│       ├── Character.cpp
│       ├── Cure.cpp
│       ├── Ice.cpp
│       └── MateriaSource.cpp
```

---

## 📘 Exercise Breakdown

### 🔁 ex00 - Polymorphism

Implements a basic inheritance structure with `Animal`, `Dog`, and `Cat`. The goal is to demonstrate virtual functions and polymorphism.

* `Animal` has:

  * A protected attribute `type`
  * Virtual method `makeSound()`
* `Dog` and `Cat` inherit from `Animal` and override `makeSound()`
* Also implements a `WrongAnimal`/`WrongCat` pair to illustrate lack of polymorphism without `virtual`.

### 🧠 ex01 - Brain & Deep Copy

Expands `Dog` and `Cat` with a `Brain` class that holds an array of 100 `std::string ideas`.

* Each animal has a `Brain*` member.
* The constructor allocates `new Brain()`, destructor deletes it.
* Implements deep copy for correct behavior when copying animals.

### 📵 ex02 - Abstract Class

The `Animal` class is made abstract to prevent direct instantiation.

* Achieved by making `makeSound()` a pure virtual function.
* Reinforces correct use of abstract base classes.

### 🧪 ex03 - Interface & Materia System

Implements a simple RPG-like system for managing magical abilities (Materia).

* **`AMateria`**: Abstract base class with `clone()` and `use()` methods.
* **`Ice` & `Cure`**: Concrete subclasses of `AMateria`.
* **`ICharacter`**: Interface for game characters.
* **`Character`**: Implements inventory, equip/unequip, and use mechanics.
* **`IMateriaSource`**: Interface for Materia generation.
* **`MateriaSource`**: Learns and creates new Materia based on type.

Demonstrates deep copying, dynamic dispatch, and interface implementation.

---

## 🧪 Build & Run

Each exercise has its own Makefile. For example:

```bash
cd ex03
make
./polymorphism
```

Make sure to test:

* Virtual destructor calls
* Proper deep copying
* Polymorphic behavior
* Interface interaction

---

## 📌 Key Concepts Reinforced

* Runtime polymorphism via virtual methods
* Abstract base classes & pure virtual functions
* Deep copy vs shallow copy
* Interface-based design in C++98
* Virtual destructors to avoid leaks

---

## 🎓 42 School Constraints

* No STL containers or algorithms (until Module 08)
* Must use Orthodox Canonical Form
* No `friend`, `using namespace`, or C++11 features
* Avoid memory leaks (use `delete` correctly)

---

## 📜 License

This project is part of the 42 School curriculum and intended for educational use only.
