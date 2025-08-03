#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &to_copy);
		FragTrap &operator=(const FragTrap &to_copy);
		~FragTrap();

		void highFivesGuys(void);
};

#endif