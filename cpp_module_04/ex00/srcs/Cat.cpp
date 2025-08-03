#include "../incs/Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Default constructor of Cat called" << std::endl;
}

Cat::Cat(const Cat &to_copy) : Animal(to_copy)
{
	std::cout << "Copy constructor of Cat called" << std::endl;
	*this = to_copy;
}

Cat &Cat::operator=(const Cat &to_copy)
{
	std::cout << "Assignment operator of Cat called" << std::endl;
	if (this != &to_copy)
		this->type = to_copy.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

std::string Cat::getType() const
{
	return this->type;
}
