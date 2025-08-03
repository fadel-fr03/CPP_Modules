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
    s1.guardGate(); // already in guard mode

    std::cout << "\n=== ScavTrap energy depletion ===" << std::endl;
    for (int i = 0; i < 51; ++i)
        s2.attack("target");

    std::cout << "\n=== ScavTrap damage and repair ===" << std::endl;
    s1.takeDamage(70);
    s1.beRepaired(20);
    s1.takeDamage(50); // should die
    s1.attack("whoever"); // can't attack when dead
    s1.guardGate();       // should still allow print but no effect

    return 0;
}