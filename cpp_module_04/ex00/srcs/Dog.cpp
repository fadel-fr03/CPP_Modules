#include "../incs/Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Default constructor of Dog called" << std::endl;
}

Dog::Dog(const Dog &to_copy) : Animal(to_copy)
{
	std::cout << "Copy constructor of Dog called" << std::endl;
	*this = to_copy;
}

Dog &Dog::operator=(const Dog &to_copy)
{
	std::cout << "Assignment operator of Dog called" << std::endl;
	if (this != &to_copy)
		this->type = to_copy.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "3AW 3AW" << std::endl;
}

std::string Dog::getType() const
{
	return this->type;
}
