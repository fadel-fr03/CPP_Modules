#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include<string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int grade_to_sign;
		const int grade_to_exec;

	public:
		// Default constructor
		Form();

		// Destructor
		~Form();

		// Copy constructor
		Form(const Form &to_copy);

		// Parametarized constructors
		Form(std::string name, int grade_to_sign, int grade_to_exec);

		// Copy assignment operator
		Form &operator=(const Form &to_copy);

		// Getters
		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		// Change sign if bureaucrat has correct grade
		void beSigned(const Bureaucrat &bur);

		//Exceptions
		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class AlreadySignedException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

// Insertion operator
std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif