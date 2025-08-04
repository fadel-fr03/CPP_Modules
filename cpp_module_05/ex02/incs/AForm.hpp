#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include<string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int grade_to_sign;
		const int grade_to_exec;
		std::string target;

	protected:
		// Does actual execution of form
		virtual void executeAction() const = 0;

	public:
		// Default constructor
		AForm();

		// Destructor
		virtual ~AForm();

		// Copy constructor
		AForm(const AForm &to_copy);

		// Parametarized constructors
		AForm(std::string name, int grade_to_sign, int grade_to_exec, std::string target);

		// Copy assignment operator
		AForm &operator=(const AForm &to_copy);

		// Getters
		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		std::string getTarget() const;

		// Change sign if bureaucrat has correct grade
		void beSigned(const Bureaucrat &bur);

		// Execute a form
		void execute(Bureaucrat const &executor) const;

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

		class NotSignedException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

// Insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif