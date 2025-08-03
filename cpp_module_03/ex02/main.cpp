#include "incs/FragTrap.hpp"
#include "incs/ScavTrap.hpp"

int main()
{
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap a("Alice");
    ClapTrap b("Bob");
    ClapTrap c;

    std::cout << "\n=== Testing ClapTrap attacks until energy runs out ===" << std::endl;
    for (int i = 0; i < 11; ++i)
        a.attack("Bob");

    std::cout << "\n=== ClapTrap takes damage ===" << std::endl;
    b.takeDamage(5);
    b.takeDamage(3);
    b.takeDamage(5);
    b.takeDamage(1);

    std::cout << "\n=== ClapTrap repairs ===" << std::endl;
    c.takeDamage(8);
    c.beRepaired(5);
    c.beRepaired(10);

    std::cout << "\n=== Draining ClapTrap repair energy ===" << std::endl;
    for (int i = 0; i < 11; ++i)
        c.beRepaired(1);

    std::cout << "\n=== ClapTrap actions after death ===" << std::endl;
    c.takeDamage(100);
    c.attack("Alice");
    c.beRepaired(3);

    std::cout << "\n=== Creating ScavTraps ===" << std::endl;
    ScavTrap s1("Serena");
    ScavTrap s2("Guardian");

    std::cout << "\n=== ScavTrap basic attack ===" << std::endl;
    s1.attack("Alice");

    std::cout << "\n=== ScavTrap guarding gate ===" << std::endl;
    s1.guardGate();
    s1.guardGate();

    std::cout << "\n=== ScavTrap energy depletion ===" << std::endl;
    for (int i = 0; i < 51; ++i)
        s2.attack("target");

    std::cout << "\n=== ScavTrap damage and repair ===" << std::endl;
    s1.takeDamage(70);
    s1.beRepaired(20);
    s1.takeDamage(50);
    s1.attack("whoever");
    s1.guardGate();

	std::cout << "\n=== Creating FragTraps ===" << std::endl;
    FragTrap f1("Fragger");
    FragTrap f2("Blaster");

    std::cout << "\n=== FragTrap high fives ===" << std::endl;
    f1.highFivesGuys();
    f2.highFivesGuys();

    std::cout << "\n=== FragTrap basic attack ===" << std::endl;
    f1.attack("some baddie");

    std::cout << "\n=== FragTrap energy drain ===" << std::endl;
    for (int i = 0; i < 101; ++i)
        f2.attack("energy eater");

    std::cout << "\n=== FragTrap repair & death ===" << std::endl;
    f1.takeDamage(60);
    f1.beRepaired(30); // valid
    f1.takeDamage(80); // should die
    f1.attack("ghost"); // should not attack
    f1.beRepaired(20);  // should not heal
    f1.highFivesGuys(); // should still print request

    std::cout << "\n=== FragTrap copy constructor & assignment ===" << std::endl;
    FragTrap f3 = f1; // copy constructor
    FragTrap f4;
    f4 = f2; // copy assignment


    return 0;
}