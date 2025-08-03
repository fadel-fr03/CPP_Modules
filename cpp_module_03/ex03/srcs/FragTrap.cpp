#include "../incs/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->name = "FragTrap";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap default constructor of " << name << " called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap parameterized constructor of " << name << " called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &to_copy) : ClapTrap(to_copy)
{
	std::cout << "FragTrap Copy Constructor has been called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &to_copy)
{
	if (this != &to_copy)
	{
		this->attack_damage = to_copy.attack_damage;
		this->hit_points = to_copy.hit_points;
		this->energy_points = to_copy.energy_points;
		this->name = to_copy.name;
	}
	std::cout << "FragTrap Copy assignment constructor has been called for " << this->name << " ." << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor of "<< this->name <<" has been called." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Tekram 3aynak 5edlak high five!!!" << std::endl;
}
