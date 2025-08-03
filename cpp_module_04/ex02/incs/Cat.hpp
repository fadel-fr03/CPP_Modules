#ifndef CAT_HPP
#define CAT_HPP

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;

	public:
		Cat();
		Cat(const Cat &to_copy);
		Cat &operator=(const Cat &to_copy);
		virtual ~Cat();

		void makeSound() const;
		std::string getType() const;
		void setIdea(std::string idea);
		void getIdeas();
};


#endif