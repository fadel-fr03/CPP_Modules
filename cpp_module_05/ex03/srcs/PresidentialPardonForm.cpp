#include "../incs/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, "default")
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& to_copy) : AForm(to_copy)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm  &to_copy)
{
	if (this != &to_copy)
		AForm::operator=(to_copy);
	return *this;
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}