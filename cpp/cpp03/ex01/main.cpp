#include "ScavTrap.hpp"

void createDestroyScavTrap(){
    std::cout << "--- START test ScavTrap functions---" << std::endl;
    ScavTrap cT1;
    ScavTrap cT2("Rudi");
    ScavTrap cT3(cT2);
    ScavTrap cT4 = cT3;

    cT1.attack("Rudi");
    cT2.beRepaired(1);
    cT4.takeDamage(10000);
    cT4.beRepaired(10);
    cT3.guardGate();
    std::cout << "--- END test ScavTrap functions---" << std::endl;
    return ;
}

int main ( void ){

    createDestroyScavTrap();

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