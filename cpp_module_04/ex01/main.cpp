#include "incs/Dog.hpp"
#include "incs/Cat.hpp"

int main()
{
    const int N = 6;
    Animal* zoo[N];

    // 1) Fill half with Dogs, half with Cats
    for (int i = 0; i < N/2; ++i)
        zoo[i] = new Dog();
    for (int i = N/2; i < N; ++i)
        zoo[i] = new Cat();

    std::cout << "\n-- All animals speak --\n\n";
    for (int i = 0; i < N; ++i)
        zoo[i]->makeSound();

    // 2) Test deep copy
    std::cout << "\n-- Deep-copy test --\n\n";
    Dog* original = new Dog();
    original->setIdea("Chase the postman");
    original->setIdea("Dig in the garden");

    Dog* clone = new Dog(*original);
    original->setIdea("Scratch the sofa");

    std::cout << "\nOriginal's ideas:\n";
    original->getIdeas();

    std::cout << "\nClone's ideas:\n";
    clone->getIdeas();
	std::cout << std::endl;

    delete original;
    delete clone;

    // 3) Clean up the zoo
    std::cout << "\n-- Cleaning up --\n\n";
    for (int i = 0; i < N; ++i)
        delete zoo[i];

    return 0;
}
