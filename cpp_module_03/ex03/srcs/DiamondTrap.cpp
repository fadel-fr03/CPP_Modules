#include "../incs/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap_clap_trap"), ScavTrap() , FragTrap()
{
	this->name = "DiamondTrap";
	this->energy_points = ScavTrap::energy_points;
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
	this->guarding_gate = false;
	std::cout << "DiamondTrap default constructor of " << name << " called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name) , FragTrap(name)
{
	this->name = name;
    this->hit_points    = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;

    std::cout << "DiamondTrap parameterized constructor of " << this->name << " called.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &to_copy) : ClapTrap(to_copy), ScavTrap(to_copy), FragTrap(to_copy)
{
	*this = to_copy;
	std::cout << "DiamondTrap Copy Constructor has been called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &to_copy)
{
	if (this != &to_copy)
	{
		ClapTrap::operator=(to_copy);
		this->name = to_copy.name;
		this->guarding_gate = false;
	}
	std::cout << "DiamondTrap Copy assignment constructor has been called for " << this->name << " ." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor of "<< this->name <<" has been called." << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name << " / ClapTrap name: " << ClapTrap::name << std::endl;
}
