#include "incs/Bureaucrat.hpp"
#include "incs/Form.hpp"
#include <iostream>

int main()
{
    // Construct and print a Bureaucrat and a Form
    try
	{
        Bureaucrat alice(50, "Alice");
        Form taxForm("TaxForm", 45, 30);

        std::cout << alice << std::endl;
        std::cout << taxForm << std::endl;

        // Alice tries to sign — grade too low for signGrade=45?
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

        // Promote Alice, then try again
        alice.incrementGrade();
        alice.incrementGrade();
        alice.incrementGrade();
        alice.incrementGrade();
        alice.incrementGrade();

        std::cout << "After promotion: " << alice << std::endl;
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;
		alice.signForm(taxForm);
    }
    catch (std::exception &e)
	{
        std::cerr << "Initialization error: " << e.what() << std::endl;
    }

    std::cout << "--------------------------------------------------------" << std::endl;

    // Try to construct a Form with invalid grades
    try
	{
        Form badForm1("BadLow", 0, 10);
    }
    catch (std::exception &e)
	{
        std::cerr << "BadLow init failed: " << e.what() << std::endl;
    }

    try
	{
        Form badForm2("BadHigh", 10, 151);
    }
    catch (std::exception &e)
	{
        std::cerr << "BadHigh init failed: " << e.what() << std::endl;
    }

    // Try a low‐grade bureaucrat signing a high‐requirement form
    try
	{
        Bureaucrat bob(140, "Bob");
        Form topSecret("TopSecret", 30, 10);
        bob.signForm(topSecret);
    }
    catch (std::exception &e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
