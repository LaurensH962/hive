#include "ClapTrap.hpp"

int main ( void ){
    ClapTrap cT1("Rudi");
    ClapTrap cT2("Jannis");

    cT1.attack("Jannis");
    cT2.takeDamage(0);
    cT2.beRepaired(8);
    cT2.attack("Rudi");
    cT1.takeDamage(0);
    cT1.beRepaired(100);
    cT1.beRepaired(100);
    cT1.beRepaired(100);
    cT1.beRepaired(100);
    cT1.beRepaired(100);
    cT1.beRepaired(100);
    cT1.beRepaired(100);
    cT1.beRepaired(100);
    cT1.beRepaired(100);
    cT1.beRepaired(100);
    cT1.beRepaired(100);
    cT1.beRepaired(100);
    cT1.beRepaired(100);
}