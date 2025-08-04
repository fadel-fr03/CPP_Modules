#include "incs/Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
	{
        Bureaucrat a(1, "Alice");
        std::cout << a << '\n';
        a.incrementGrade();
    }
    catch (std::exception &e)
	{
        std::cerr << "Error: " << e.what() << '\n';
    }

    try
	{
        Bureaucrat b(150, "Bob");
        std::cout << b << '\n';
        b.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    // constructor exceptions
    try
	{
        Bureaucrat c(0, "Charlie");
    }
    catch (std::exception &e)
	{
        std::cerr << "Charlie init failed: " << e.what() << '\n';
    }

    try
	{
        Bureaucrat d(151, "David");
    }
    catch (std::exception &e)
	{
        std::cerr << "David init failed: " << e.what() << '\n';
    }

    return 0;
}
