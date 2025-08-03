#include "../incs/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack(void) const
{
	if (!this->weapon && this->weapon->getType().empty())
	{
		std::cout << this->name << " doesn't have a weapon to attack."
							<< this->weapon->getType() << std::endl;
	}
	else
	{
		std::cout << this->name << " attacks with their "
							<< this->weapon->getType() << std::endl;
	}
}
