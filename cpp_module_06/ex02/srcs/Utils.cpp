#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"

Base *generate()
{
    std::srand(std::time(0));
    int r = std::rand() % 3;
    if (r == 0)
	{
		std::cout << "Class of type A was generated" << std::endl;
		return new A();
	}
	else if (r == 1)
	{
		std::cout << "Class of type B was generated" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "Class of type C was generated" << std::endl;
		return new C();
	}
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type: C" << std::endl;
    else
        std::cout << "This class is not any of the types A, B or C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
		return;
	}
	catch(std::exception &e){}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
		return;
	}
	catch(std::exception &e){}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
		return;
	}
	catch(std::exception &e){}

	std::cout << "This class is not any of the types A, B or C" << std::endl;
}
