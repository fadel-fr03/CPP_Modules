#include "../incs/Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup" \
	" burger.\nI really do!\n" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\n" << \
		"You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" \
		<< std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\n" \
	"I've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	// array of pointers to member functions
	void (Harl::*handlers[])() =
	{
    	&Harl::debug,
    	&Harl::info,
    	&Harl::warning,
    	&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*handlers[i])();
			break;
		}
	}
}