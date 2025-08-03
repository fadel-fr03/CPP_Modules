#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ClapTrap"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap default constructor of " << name << " called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap parameterized constructor of " << name << " called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &to_copy)
{
	*this = to_copy;
	std::cout << "ClapTrap Copy Constructor has been called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &to_copy)
{
	if (this != &to_copy)
	{
		this->attack_damage = to_copy.attack_damage;
		this->hit_points = to_copy.hit_points;
		this->energy_points = to_copy.energy_points;
		this->name = to_copy.name;
	}
	std::cout << "ClapTrap Copy assignment constructor has been called for " << this->name << " ." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor of "<< this->name <<" has been called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead and can't attack!" << std::endl;
	}
	else if (energy_points <= 0)
		std::cout << "ClapTrap " << name << " is out of energy points!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_damage \
						<< " points of damage!" << std::endl;
		this->energy_points--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " is already dead, stop hitting his lifeless body!" << std::endl;
	else if (this->hit_points <= amount)
	{
		this->hit_points = 0;
		std::cout << "ClapTrap " << this->name << " was attacked and is now dead!" << std::endl;
	}
	else
	{
		this->hit_points -= amount;
		std::cout << "ClapTrap " << this->name << " was attacked and took " << amount << " damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " is already dead and can't be resurrected!" << std::endl;
	else if (energy_points <= 0)
		std::cout << "ClapTrap " << this->name << " is out of energy points!" << std::endl;
	else if (this->hit_points + amount > 10)
		std::cout << "ClapTrap " << this->name << " can't have more than 10 hitpoints!" << std::endl;
	else
	{
		this->hit_points += amount;
		this->energy_points--;
		std::cout << "ClapTrap " << this->name << " has been healed and now has " \
			<< this->hit_points << " hit points!" << std::endl;
	}
}
