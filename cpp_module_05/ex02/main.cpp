#include "incs/Bureaucrat.hpp"
#include "incs/ShrubberyCreationForm.hpp"
#include "incs/RobotomyRequestForm.hpp"
#include "incs/PresidentialPardonForm.hpp"

int main()
{
    std::cout << "=== Testing Form Creation ===" << std::endl;

    try 
    {
        // Create bureaucrats with different grades
        Bureaucrat alice(1, "Alice");
        Bureaucrat bob(50, "Bob");
        Bureaucrat charlie(150, "Charlie");

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;
        std::cout << std::endl;

        // Create forms
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur_Dent");

        std::cout << "=== Testing Form Information ===" << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
        std::cout << std::endl;

        std::cout << "=== Testing Form Signing ===" << std::endl;

        // Test signing with appropriate grades
        std::cout << "Alice trying to sign ShrubberyCreationForm:" << std::endl;
        alice.signForm(shrub);
        std::cout << shrub << std::endl;
        std::cout << std::endl;

        std::cout << "Bob trying to sign RobotomyRequestForm:" << std::endl;
        bob.signForm(robot);
        std::cout << robot << std::endl;
        std::cout << std::endl;

        std::cout << "Alice trying to sign PresidentialPardonForm:" << std::endl;
        alice.signForm(pardon);
        std::cout << pardon << std::endl;
        std::cout << std::endl;

        // Test signing with insufficient grade
        std::cout << "Charlie trying to sign ShrubberyCreationForm:" << std::endl;
        charlie.signForm(shrub);
        std::cout << std::endl;

        std::cout << "=== Testing Form Execution ===" << std::endl;

        // Test execution with appropriate grades
        std::cout << "Alice executing ShrubberyCreationForm:" << std::endl;
        alice.executeForm(shrub);
        std::cout << std::endl;

        std::cout << "Alice executing RobotomyRequestForm:" << std::endl;
        alice.executeForm(robot);
        std::cout << std::endl;

        std::cout << "Alice executing PresidentialPardonForm:" << std::endl;
        alice.executeForm(pardon);
        std::cout << std::endl;

        // Test execution with insufficient grade
        std::cout << "Charlie trying to execute ShrubberyCreationForm:" << std::endl;
        charlie.executeForm(shrub);
        std::cout << std::endl;

        // Test execution of unsigned form
        std::cout << "Creating unsigned RobotomyRequestForm:" << std::endl;
        RobotomyRequestForm unsignedRobot("Wall-E");
        std::cout << "Alice trying to execute unsigned form:" << std::endl;
        alice.executeForm(unsignedRobot);
        std::cout << std::endl;

        std::cout << "=== Testing Exception Cases ===" << std::endl;

        // Test already signed form
        std::cout << "Trying to sign already signed form:" << std::endl;
        try 
        {
            shrub.beSigned(alice);
        }
        catch (const std::exception& e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        std::cout << std::endl;

        // Test robotomy multiple times to see randomness
        std::cout << "=== Testing Robotomy Randomness ===" << std::endl;
        RobotomyRequestForm robot2("R2D2");
        alice.signForm(robot2);

        for (int i = 0; i < 5; i++)
        {
            std::cout << "Robotomy attempt " << (i + 1) << ":" << std::endl;
            alice.executeForm(robot2);
            std::cout << std::endl;
        }

        std::cout << "=== Testing Grade Requirements ===" << std::endl;

        // Test different grade requirements
        Bureaucrat lowGrade(100, "LowGrade");
        Bureaucrat midGrade(50, "MidGrade");
        Bureaucrat highGrade(10, "HighGrade");

        ShrubberyCreationForm shrub2("garden");
        RobotomyRequestForm robot3("C3PO");
        PresidentialPardonForm pardon2("Ford_Prefect");
 
        // Sign forms with appropriate bureaucrats
        lowGrade.signForm(shrub2);
        midGrade.signForm(robot3);
        highGrade.signForm(pardon2);

        std::cout << std::endl;

        // Try to execute with different grades
        std::cout << "Testing execution with different grades:" << std::endl;
        lowGrade.executeForm(shrub2);
        midGrade.executeForm(robot3);
        highGrade.executeForm(pardon2);

        // Alice can execute all
        std::cout << std::endl << "Alice executing all forms:" << std::endl;
        alice.executeForm(shrub2);
        alice.executeForm(robot3);
        alice.executeForm(pardon2);
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}