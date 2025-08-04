#include "../incs/Form.hpp"

Form::Form() : name("Form"), isSigned(false), grade_to_sign(75), grade_to_exec(75)
{}

Form::~Form()
{}

Form::Form(const Form &to_copy) : name(to_copy.getName()),
	isSigned(to_copy.getIsSigned()), grade_to_sign(to_copy.getSignGrade()),
	grade_to_exec(to_copy.getExecGrade())
{}

Form::Form(std::string name, int grade_to_sign, int grade_to_exec) : name(name), isSigned(false),
	grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec)
{
	if (grade_to_sign > 150 || grade_to_exec > 150)
		throw GradeTooLowException();
	else if (grade_to_sign < 1 || grade_to_exec < 1)
		throw GradeTooHighException();
}

Form &Form::operator=(const Form &to_copy)
{
	if (this != &to_copy)
		this->isSigned = to_copy.getIsSigned();
	return *this;
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getSignGrade() const
{
	return this->grade_to_sign;
}

int Form::getExecGrade() const
{
	return this->grade_to_exec;
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form grade too low.");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form grade too high.");
};

const char *Form::AlreadySignedException::what(void) const throw()
{
	return ("Form already signed.");
};

void Form::beSigned(const Bureaucrat &bur)
{
	if (isSigned)
        throw AlreadySignedException();
    if (bur.getGrade() > grade_to_sign)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName()
   << ", sign grade " << obj.getSignGrade()
   << ", exec grade " << obj.getExecGrade()
   << (obj.getIsSigned() ? " (signed)" : " (not signed)");

   return os;
}
