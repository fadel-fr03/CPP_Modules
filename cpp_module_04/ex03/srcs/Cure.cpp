#include "../incs/Cure.hpp"

Cure::Cure() : AMateria("cure"){}

Cure::Cure(const Cure &to_copy) : AMateria(to_copy)
{
	*this = to_copy;
}

Cure &Cure::operator=(const Cure &to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	return *this;
}

Cure::~Cure() {}

Cure *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
