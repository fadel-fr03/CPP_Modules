#include "../incs/Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Default constructor of Animal called" << std::endl;
}

Animal::Animal(const Animal &to_copy)
{
	std::cout << "Copy constructor of Animal called" << std::endl;
	*this = to_copy;
}

Animal &Animal::operator=(const Animal &to_copy)
{
	std::cout << "Assignment operator of Animal called" << std::endl;
	if (this != &to_copy)
		this->type = to_copy.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Destructor of Animal called" << std::endl;
}
