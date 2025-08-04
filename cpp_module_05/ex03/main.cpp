#include "incs/Intern.hpp"
#include "incs/Bureaucrat.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;

		AForm *form1 = someRandomIntern.makeForm("shrubbery creation", "Bender");
		AForm *form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Bender");

        Bureaucrat boss(1, "Boss");
        boss.signForm(*form2);
        boss.executeForm(*form2);

		(void)form1;
		(void)form3;

		delete form1;
        delete form2;
        delete form3;

        std::cout << "\nTrying unknown form...\n";
        someRandomIntern.makeForm("coffee request", "Barista");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
