# C++ Module 05 - Repetition and Exceptions

&#x20;

This module builds upon object-oriented programming concepts by introducing exception handling and polymorphism in the context of a bureaucracy simulation. It involves designing classes that model bureaucrats, forms, and interactions between them using polymorphism and robust error handling through exceptions.

---

## 📂 Table of Contents

* [📂 Project Structure](#-project-structure)
* [📘 Exercise Breakdown](#-exercise-breakdown)

  * [💼 ex00 - Bureaucrat Class](#-ex00---bureaucrat-class)
  * [🤠 ex01 - Form Class](#-ex01---form-class)
  * [📄 ex02 - Specialized Forms (AForm)](#-ex02---specialized-forms-aform)
  * [🧑‍💼 ex03 - Intern Class](#-ex03---intern-class)
* [🧪 Build & Run](#-build--run)
* [🔹 Key Concepts Reinforced](#-key-concepts-reinforced)
* [🎓 42 School Constraints](#-42-school-constraints)
* [📜 License](#-license)

---

## 📂 Project Structure

```
cpp_module_05/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/Bureaucrat.hpp
│   └── srcs/Bureaucrat.cpp
│
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/Bureaucrat.hpp  # updated
│   ├── incs/Form.hpp
│   ├── srcs/Bureaucrat.cpp
│   └── srcs/Form.cpp
│
├── ex02/
│   ├── Makefile
│   ├── main.cpp
│   ├── incs/AForm.hpp
│   ├── incs/Bureaucrat.hpp
│   ├── incs/PresidentialPardonForm.hpp
│   ├── incs/RobotomyRequestForm.hpp
│   └── incs/ShrubberyCreationForm.hpp
│   └── srcs/...
│
├── ex03/
    ├── Makefile
    ├── main.cpp
    ├── incs/AForm.hpp
    ├── incs/Bureaucrat.hpp
    ├── incs/Intern.hpp
    ├── incs/PresidentialPardonForm.hpp
    ├── incs/RobotomyRequestForm.hpp
    └── incs/ShrubberyCreationForm.hpp
    └── srcs/...
```

---

## 📘 Exercise Breakdown

### 💼 ex00 - Bureaucrat Class

Implements the `Bureaucrat` class that represents an office worker.

* **Attributes**:

  * `const std::string name`
  * `int grade` (range: 1 \[highest] to 150 \[lowest])

* **Member Functions**:

  * `getName()` / `getGrade()`
  * `incrementGrade()` / `decrementGrade()`

    * Throws `GradeTooHighException` or `GradeTooLowException` if invalid.
  * Custom `<<` operator for printing:

    ```
    <name>, bureaucrat grade <grade>.
    ```

* **Exception Handling**:

  * Proper exception classes for grade bounds.
  * Try-catch usage is tested in main.

---

### 🤠 ex01 - Form Class

Adds the `Form` class and connects it with `Bureaucrat`.

* **Attributes**:

  * `const std::string name`
  * `bool isSigned`
  * `const int gradeToSign`
  * `const int gradeToExecute`

* **Rules**:

  * Form is signed only if Bureaucrat has high enough grade.
  * Grade bounds throw `Form::GradeTooHighException` or `Form::GradeTooLowException`.

* **Methods**:

  * `beSigned(const Bureaucrat &)`
  * Getters for all attributes
  * Overload `<<` to print form state

* **Bureaucrat Enhancement**:

  * `signForm(Form &form)` method added, with contextual output:

    ```
    Bob signed TaxForm
    Bob couldn't sign TaxForm because GradeTooLowException
    ```

---

### 📄 ex02 - Specialized Forms (AForm)

Refactors `Form` into abstract base class `AForm`.

* **Abstract Base**: `AForm` contains the common logic and adds a pure virtual `execute()` method.

* **Concrete Classes**:

  * `ShrubberyCreationForm`: creates a `<target>_shrubbery` file with ASCII trees.

    * Required Grades: sign=145, exec=137
  * `RobotomyRequestForm`: 50% chance to say `<target> has been robotomized`.

    * Required Grades: sign=72, exec=45
  * `PresidentialPardonForm`: `<target> has been pardoned by Zaphod Beeblebrox.`

    * Required Grades: sign=25, exec=5

* **Execution Requirements**:

  * Must be signed
  * Bureaucrat's grade must be high enough
  * Otherwise: throw exceptions and catch in main

* **New Bureaucrat Method**:

  * `executeForm(const AForm &form)`

    ```
    Bob executed RobotomyRequestForm
    Bob couldn't execute because not signed / grade too low
    ```

---

### 🧑‍💼 ex03 - Intern Class

Implements the `Intern` class which can generate form instances.

* **Key Method**:

  ```cpp
  AForm* makeForm(std::string const &formName, std::string const &target);
  ```

* **Behavior**:

  * Accepts form name like: "robotomy request"
  * Creates corresponding form using dynamic allocation
  * Prints: `Intern creates <form>`
  * If name invalid: print error

* **Design Requirement**:

  * Avoid long if/else chains — favor arrays, switch, or polymorphic maps.

* **Test Example**:

  ```cpp
  Intern intern;
  AForm* form = intern.makeForm("shrubbery creation", "Garden");
  delete form;
  ```

---

## 🧪 Build & Run

Each exercise includes its own Makefile. Example:

```bash
cd ex03
make
./internWork
```

Ensure you test:

* Boundary exceptions (grades out of range)
* Form signing/execution conditions
* Deep copy behavior (where relevant)
* Proper memory cleanup

---

## 🔹 Key Concepts Reinforced

* Exception handling using try/catch and custom exceptions
* Operator overloading
* Inheritance and polymorphism
* Abstract classes and pure virtual methods
* Separation of interface and implementation
* Dependency inversion with Intern factory logic

---

## 🎓 42 School Constraints

* Orthodox Canonical Form (Rule of 4) for all but exception classes
* No C++11 or STL containers/algorithms
* No `using namespace std` or `friend` keywords
* All headers must be self-contained and protected against multiple inclusion
* File I/O allowed only where required (e.g., ShrubberyCreationForm)

---

## 📜 License

This project is part of the 42 School curriculum and is intended for educational purposes only.
