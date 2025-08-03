#include "incs/ClapTrap.hpp"

int main()
{
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap a("Alice");
    ClapTrap b("Bob");
    ClapTrap c;

    std::cout << "\n=== Testing attacks until energy runs out ===" << std::endl;
    for (int i = 0; i < 11; ++i)
    {
        a.attack("Bob");
    }

    std::cout << "\n=== Testing takeDamage ===" << std::endl;
    b.takeDamage(5);
    b.takeDamage(3);
    b.takeDamage(5);  // should drop Bob to 0 HP
    b.takeDamage(1);  // trying to damage a "dead" ClapTrap

    std::cout << "\n=== Testing repairs ===" << std::endl;
    c.takeDamage(8);          // bring c down to 2 HP
    c.beRepaired(5);          // legal repair: 2 + 5 = 7
    c.beRepaired(10);         // should trigger "can't have more than max HP"

    std::cout << "\n=== Draining repair energy ===" << std::endl;
    for (int i = 0; i < 11; ++i)
    {
        c.beRepaired(1);       // costs energy until out
    }

    std::cout << "\n=== Testing actions after death ===" << std::endl;
    c.takeDamage(100);        // kill c
    c.attack("Alice");      // can't attack when dead
    c.beRepaired(3);          // can't repair when dead

    return 0;
}
