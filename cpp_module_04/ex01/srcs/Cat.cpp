#include "../incs/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Default constructor of Cat called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(Cat const & src) : Animal(src) , brain(new Brain(*src.brain))
{
    std::cout << "Copy constructor of Cat called\n";
}

Cat &Cat::operator=(const Cat &to_copy)
{
	std::cout << "Assignment operator of Cat called" << std::endl;
	if (this != &to_copy)
	{
		this->type = to_copy.type;
		*this->brain = *to_copy.brain;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

std::string Cat::getType() const
{
	return this->type;
}

void Cat::setIdea(std::string idea)
{
	this->brain->setIdea(idea);
}

void Cat::getIdeas()
{
	for (int i = 1; i <= this->brain->number_ideas; i++)
		std::cout << "Idea " << i << ": " << this->brain->getIdea(i) << std::endl;
}
