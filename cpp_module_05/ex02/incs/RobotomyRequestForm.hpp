#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		void executeAction() const;

	public:
        // Default constructor
        RobotomyRequestForm();

		// Destructor
        ~RobotomyRequestForm();

		// Copy constructor
        RobotomyRequestForm(const RobotomyRequestForm& to_copy);

        // Parametrized constructor
        RobotomyRequestForm(const std::string &target);

        // Assignment operator
        RobotomyRequestForm &operator=(const RobotomyRequestForm &to_copy);
};

#endif