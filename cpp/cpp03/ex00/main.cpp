#include "ClapTrap.hpp"

void createDestroyClapTrap(){
    std::cout << "--- START test ClapTrap functions---" << std::endl;
    ClapTrap cT1;
    ClapTrap cT2("Rudi");
    ClapTrap cT3(cT2);
    ClapTrap cT4 = cT3;

    cT1.attack("Rudi");
    cT2.beRepaired(1);
    cT4.takeDamage(10000);
    cT4.beRepaired(10);
    std::cout << "--- END test ClapTrap functions---" << std::endl;
    return ;
}

int main ( void ){
    createDestroyClapTrap();

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