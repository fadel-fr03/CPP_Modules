#include "../incs/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(75)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat &to_copy) : name(to_copy.getName()), grade(to_copy.getGrade())
{}

Bureaucrat::Bureaucrat(int grade) : name("Bureaucrat")
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(75)
{}

Bureaucrat::Bureaucrat(int grade, std::string name) : name(name)
{
	this->setGrade(grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &to_copy)
{
	if (this != &to_copy)
		this->setGrade(to_copy.getGrade());
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

void Bureaucrat::decrementGrade()
{
	this->setGrade(this->getGrade() + 1);
}

void Bureaucrat::incrementGrade()
{
	this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::signForm(Form &form) const
{
    try
	{
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << "\n";
    }
	catch (std::exception &e)
	{
        std::cout << name
                  << " couldn't sign " << form.getName()
                  << " because " << e.what() << "\n";
    }
}


const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}
