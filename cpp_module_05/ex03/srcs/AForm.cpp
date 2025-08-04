#include "../incs/AForm.hpp"

AForm::AForm() : name("Form"), isSigned(false), grade_to_sign(75), grade_to_exec(75)
{}

AForm::~AForm()
{}

AForm::AForm(const AForm &to_copy) : name(to_copy.getName()),
	isSigned(to_copy.getIsSigned()), grade_to_sign(to_copy.getSignGrade()),
	grade_to_exec(to_copy.getExecGrade()), target(to_copy.getTarget())
{}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec, std::string target) : name(name), isSigned(false),
	grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec), target(target)
{
	if (grade_to_sign > 150 || grade_to_exec > 150)
		throw GradeTooLowException();
	else if (grade_to_sign < 1 || grade_to_exec < 1)
		throw GradeTooHighException();
}

AForm &AForm::operator=(const AForm &to_copy)
{
	if (this != &to_copy)
	{
		this->isSigned = to_copy.getIsSigned();
		this->target = to_copy.getTarget();
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getSignGrade() const
{
	return this->grade_to_sign;
}

int AForm::getExecGrade() const
{
	return this->grade_to_exec;
}

std::string AForm::getTarget() const
{
	return this->target;
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form grade too low.");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form grade too high.");
};

const char *AForm::AlreadySignedException::what(void) const throw()
{
	return ("Form already signed.");
};

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("Form is not signed.");
};

void AForm::beSigned(const Bureaucrat &bur)
{
	if (isSigned)
        throw AlreadySignedException();
    if (bur.getGrade() > grade_to_sign)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName()
   << ", sign grade " << obj.getSignGrade()
   << ", exec grade " << obj.getExecGrade()
   << (obj.getIsSigned() ? " (signed)" : " (not signed)");

   return os;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned)
        throw NotSignedException();
    if (executor.getGrade() > grade_to_exec)
        throw GradeTooLowException();
    executeAction();
}
