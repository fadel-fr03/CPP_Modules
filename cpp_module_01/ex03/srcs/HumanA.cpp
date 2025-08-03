#include "../incs/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack(void) const
{
	if (this->weapon.getType().empty())
	{
		std::cout << this->name << " doesn't have a weapon to attack."
							<< this->weapon.getType() << std::endl;
	}
	else
	{
		std::cout << this->name << " attacks with their "
							<< this->weapon.getType() << std::endl;
	}
}