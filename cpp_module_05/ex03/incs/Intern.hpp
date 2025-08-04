#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>
# include <iostream>
# include <stdexcept>

class Intern
{
    public:
		// Default constructor
        Intern();
		// Copy constructor
        Intern(const Intern &to_copy);
		// Equal Assignment Operator
        Intern &operator=(const Intern &to_copy);
		// Destructor
        ~Intern();

        AForm *makeForm(std::string formType, std::string target);

        class UnknownFormException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif
