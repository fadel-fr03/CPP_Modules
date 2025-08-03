#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool guarding_gate;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &to_copy);
		ScavTrap &operator=(const ScavTrap &to_copy);
		~ScavTrap();

		void attack(const std::string &target);
		void guardGate(void);
};

#endif