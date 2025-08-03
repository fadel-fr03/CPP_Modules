#include "incs/Cat.hpp"
#include "incs/Dog.hpp"
#include "incs/WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	std::cout << std::endl;

	std::cout << "Animal type: " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	const Animal *cat = new Cat();
	std::cout << std::endl;

	std::cout << "Cat type: " << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << std::endl;

	delete cat;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	const Animal *dog = new Dog();
	std::cout << std::endl;
	std::cout << "Dog type: " << dog->getType() <<std::endl;
	dog->makeSound();
	std::cout << std::endl;
	delete dog;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	const WrongAnimal *wrong_meta = new WrongAnimal();
	std::cout << std::endl;

	std::cout << "Animal type: " << wrong_meta->getType() << std::endl;
	wrong_meta->makeSound();
	std::cout << std::endl;

	delete wrong_meta;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	const WrongAnimal *wrong_cat = new WrongCat();
	std::cout << std::endl;

	std::cout << "WrongCat type: " << wrong_cat->getType() <<std::endl;
	wrong_cat->makeSound();
	std::cout << std::endl;

	delete wrong_cat;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	const WrongCat *wrong_catt = new WrongCat();
	std::cout << std::endl;

	std::cout << "WrongCat type: " << wrong_catt->getType() <<std::endl;
	wrong_catt->makeSound();
	std::cout << std::endl;
	delete wrong_catt;
	std::cout << std::endl;

	return (0);
}