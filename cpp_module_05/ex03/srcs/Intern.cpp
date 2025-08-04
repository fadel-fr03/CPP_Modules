#include "../incs/Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(const Intern &)
{}

Intern &Intern::operator=(const Intern &)
{
	return *this;
}

const char *Intern::UnknownFormException::what() const throw()
{
    return "Unknown form type requested.";
}

// Static creator functions
static AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formType, std::string target)
{
    const std::string formNames[3] =
	{
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *(*formCreators[3])(const std::string &) =
	{
        &createShrubbery,
        &createRobotomy,
        &createPardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (formType == formNames[i])
        {
            std::cout << "Intern creates " << formType << " form." << std::endl;
            return formCreators[i](target);
        }
    }
    throw Intern::UnknownFormException();
}
