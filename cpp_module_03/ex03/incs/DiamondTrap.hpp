#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &to_copy);
		DiamondTrap &operator=(const DiamondTrap &to_copy);
		~DiamondTrap();

		void attack(const std::string& target);
		void whoAmI();
};

#endif