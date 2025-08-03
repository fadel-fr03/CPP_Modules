#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &to_copy);
		ClapTrap &operator=(const ClapTrap &to_copy);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif