#include "../incs/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, "default")
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& to_copy) : AForm(to_copy)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45, target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm  &to_copy)
{
	if (this != &to_copy)
		AForm::operator=(to_copy);
	return *this;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* DRILLING NOISES *" << std::endl;
    std::cout << "BZZZZZZT! WHIRRRRRR! CLANK CLANK!" << std::endl;

    std::srand(std::time(0));

    if (std::rand() % 2 == 0)
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy of " << getTarget() << " failed!" << std::endl;
}