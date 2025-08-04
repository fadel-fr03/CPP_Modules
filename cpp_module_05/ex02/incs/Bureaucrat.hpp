#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include<string>
#include "AForm.hpp"

class AForm; 

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		// Default constructor
		Bureaucrat();

		// Destructor
		~Bureaucrat();

		// Copy constructor
		Bureaucrat(const Bureaucrat &to_copy);

		// Parametarized constructors
		Bureaucrat(int grade);
		Bureaucrat(std::string name);
		Bureaucrat(int grade, std::string name);

		// Copy assignment operator
		Bureaucrat &operator=(const Bureaucrat &to_copy);

		// Getters
		std::string getName() const;
		int getGrade() const;

		// setters (name does not have one as it's const)
		void setGrade(int grade);

		// Decrement/Increment grade
		void decrementGrade();
		void incrementGrade();

		//Sign a form
		void signForm(AForm &form) const;

		// Execute a form
		void executeForm(AForm const &form);

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
};

// Insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif