#include "ScavTrap.hpp"

int main ( void ){
    ScavTrap cT1("Rudi");
    ScavTrap cT2("Jannis");

    cT1.attack("Jannis");
    cT2.takeDamage(20);
    cT2.beRepaired(23);
    cT2.attack("Rudi");
    cT1.takeDamage(20);
    cT1.beRepaired(100);
    cT2.attack("Rudi");
    cT1.takeDamage(20);
    cT2.attack("Rudi");
    cT1.takeDamage(20);
    cT2.attack("Rudi");
    cT1.takeDamage(20);
    cT2.attack("Rudi");
    cT1.takeDamage(20);
    cT2.attack("Rudi");
    cT1.takeDamage(20);
    cT2.attack("Rudi");
    cT1.takeDamage(20);
    cT2.attack("Rudi");
    cT1.takeDamage(20);
    cT2.attack("Rudi");
    cT1.takeDamage(20);
    cT2.attack("Rudi");
    cT1.takeDamage(20);
    cT2.attack("Rudi");
    cT1.takeDamage(20);
    cT2.attack("Rudi");
    cT1.takeDamage(20);
    cT1.beRepaired(100);
    cT1.beRepaired(100);

    cT1.guardGate();
}