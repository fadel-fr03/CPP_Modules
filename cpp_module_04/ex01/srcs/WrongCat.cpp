#include "../incs/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "Default constructor of WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &to_copy) : WrongAnimal(to_copy)
{
	std::cout << "Copy constructor of WrongCat called" << std::endl;
	*this = to_copy;
}

WrongCat &WrongCat::operator=(const WrongCat &to_copy)
{
	std::cout << "Assignment operator of WrongCat called" << std::endl;
	if (this != &to_copy)
		this->type = to_copy.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor of WrongCat called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

std::string WrongCat::getType() const
{
	return this->type;
}
