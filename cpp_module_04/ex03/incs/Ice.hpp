#ifndef ICE_HPP
#define ICE_HPP

#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &to_copy);
		Ice &operator=(const Ice &to_copy);
		~Ice();

		virtual Ice *clone() const;
		virtual void use(ICharacter &target);
};

#endif