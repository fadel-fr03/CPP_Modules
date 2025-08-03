#include "../incs/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->name = "ScavTrap";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->guarding_gate = false;
	std::cout << "ScavTrap default constructor of " << name << " called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->guarding_gate = false;
	std::cout << "ScavTrap parameterized constructor of " << name << " called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &to_copy) : ClapTrap(to_copy)
{
	this->guarding_gate = false;
	std::cout << "ScavTrap Copy Constructor has been called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &to_copy)
{
	if (this != &to_copy)
	{
		this->attack_damage = to_copy.attack_damage;
		this->hit_points = to_copy.hit_points;
		this->energy_points = to_copy.energy_points;
		this->name = to_copy.name;
		this->guarding_gate = to_copy.guarding_gate;
	}
	std::cout << "ScavTrap Copy assignment constructor has been called for " << this->name << " ." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor of "<< this->name <<" has been called." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hit_points == 0)
	{
		std::cout << "ScavTrap " << this->name << " is already dead and can't attack!" << std::endl;
	}
	else if (energy_points <= 0)
		std::cout << "ScavTrap " << name << " is out of energy points!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attack_damage \
						<< " points of damage!" << std::endl;
		this->energy_points--;
	}
}

void ScavTrap::guardGate(void)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead, so guarding gate mode can't be activated!" << std::endl;
	}
	if (this->guarding_gate == false)
	{
		this->guarding_gate = true;
		std::cout << "ScavTrap " << this->name << " is now in guarding gate mode!" << std::endl;
	}
	else
	std::cout << "ScavTrap " << this->name << " is already in guarding gate mode!" << std::endl;
}
