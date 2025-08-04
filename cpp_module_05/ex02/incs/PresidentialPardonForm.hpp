#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		void executeAction() const;

	public:
        // Default constructor
        PresidentialPardonForm();

		// Destructor
        ~PresidentialPardonForm();

		// Copy constructor
        PresidentialPardonForm(const PresidentialPardonForm& to_copy);

        // Parametrized constructor
        PresidentialPardonForm(const std::string &target);

        // Assignment operator
        PresidentialPardonForm &operator=(const PresidentialPardonForm &to_copy);
};

#endif