#include "incs/Base.hpp"
#include "incs/A.hpp"
#include "incs/B.hpp"
#include "incs/C.hpp"
#include <iostream>

Base* generate();
void identify(Base *p);
void identify(Base &p);


int main()
{
    Base* ptr = generate();

    std::cout << "Using pointer:\n";
    identify(ptr);

    std::cout << "Using reference:\n";
    identify(*ptr);

    delete ptr;
    return 0;
}
