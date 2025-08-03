#include "incs/Harl.hpp"

int main(void)
{
	std::string input;
	Harl harl;

	std::cout << "Enter a level: ";
	std::cin >> input;
	harl.complain(input);

	return 0;
}
