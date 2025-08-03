#include "../incs/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "Default constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &to_copy)
{
	std::cout << "Copy constructor of WrongAnimal called" << std::endl;
	*this = to_copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &to_copy)
{
	std::cout << "Assignment operator of WrongAnimal called" << std::endl;
	if (this != &to_copy)
		this->type = to_copy.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
