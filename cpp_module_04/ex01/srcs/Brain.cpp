#include "../incs/Brain.hpp"

Brain::Brain()
{
	this->number_ideas = 0;
	std::cout << "Default constructor of Brain called" << std::endl;
}

Brain::Brain(const Brain &to_copy)
{
	std::cout << "Copy constructor of Brain called" << std::endl;
	*this = to_copy;
}

Brain &Brain::operator=(const Brain &to_copy)
{
	std::cout << "Assignment operator of Brain called" << std::endl;
	if (this != &to_copy)
	{
		for (int i = 0; i < to_copy.number_ideas; ++i)
   			this->ideas[i] = to_copy.ideas[i];
		this->number_ideas = to_copy.number_ideas;
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Destructor of Brain called" << std::endl;
}

void Brain::setIdea(std::string idea)
{
	if (this->number_ideas == 100)
	{
		std::cout << "The tiny brain can't have anymore ideas!" << std::endl;
		return;
	}
	this->ideas[number_ideas] = idea;
	this->number_ideas++;
	std::cout << "Idea: " << idea << " has been added!" << std::endl;
}

std::string Brain::getIdea(int i)
{
	if (i > 100 || i <= 0)
	{
		std::cout << "An animal's brain can have have at least 1 idea and at most 100 ideas" << std::endl;
		return "";
	}
	else if (i > this->number_ideas)
	{
		std::cout << "This animal does not have " << i << " ideas." << std::endl;
		return "";
	}
	else
		return ideas[i - 1];
}