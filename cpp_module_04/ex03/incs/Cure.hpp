#ifndef CURE_HPP
#define CURE_HPP

#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &to_copy);
		Cure &operator=(const Cure &to_copy);
		~Cure();

		virtual Cure *clone() const;
		virtual void use(ICharacter &target);
};

#endif