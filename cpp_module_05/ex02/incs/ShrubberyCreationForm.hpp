#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		void executeAction() const;

	public:
        // Default constructor
        ShrubberyCreationForm();

		// Destructor
        ~ShrubberyCreationForm();

		// Copy constructor
        ShrubberyCreationForm(const ShrubberyCreationForm& to_copy);

        // Parametrized constructor
        ShrubberyCreationForm(const std::string &target);

        // Assignment operator
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &to_copy);
};

#endif