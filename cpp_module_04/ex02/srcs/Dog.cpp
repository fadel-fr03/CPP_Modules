#include "../incs/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Default constructor of Dog called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog const & src) : Animal(src) , brain(new Brain(*src.brain))
{
    std::cout << "Copy constructor of Dog called\n";
}

Dog &Dog::operator=(const Dog &to_copy)
{
	std::cout << "Assignment operator of Dog called" << std::endl;
	if (this != &to_copy)
	{
		this->type = to_copy.type;
		*this->brain = *to_copy.brain;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog called" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << "3AW 3AW" << std::endl;
}

std::string Dog::getType() const
{
	return this->type;
}

void Dog::setIdea(std::string idea)
{
	this->brain->setIdea(idea);
}

void Dog::getIdeas()
{
	for (int i = 1; i <= this->brain->number_ideas; i++)
		std::cout << "Idea " << i << ": " << this->brain->getIdea(i) << std::endl;
}
