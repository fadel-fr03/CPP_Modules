#include "../incs/Ice.hpp"

Ice::Ice() : AMateria("ice"){}

Ice::Ice(const Ice &to_copy) : AMateria(to_copy)
{
	*this = to_copy;
}

Ice &Ice::operator=(const Ice &to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	return *this;
}

Ice::~Ice() {}

Ice *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}
