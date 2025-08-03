#include "../incs/AMateria.hpp"

AMateria::AMateria() : type("") {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria &to_copy)
{
	*this = to_copy;
}
AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria " << this->type << " used on " << target.getName() << std::endl;
}