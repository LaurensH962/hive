#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void createDestroyFragTrap(){
    std::cout << "--- START test FragTrap functions---" << std::endl;
    FragTrap cT1;
    FragTrap cT2("Rudi");
    FragTrap cT3(cT2);
    FragTrap cT4 = cT3;

    cT1.attack("Rudi");
    cT2.beRepaired(1);
    cT4.takeDamage(10000);
    cT4.beRepaired(10);
    cT3.highFivesGuys();
    cT4.highFivesGuys();
    std::cout << "--- END test FragTrap functions---" << std::endl;
    return ;
}

int main ( void ){
    createDestroyFragTrap();

    FragTrap cT1("Rudi");
    FragTrap cT2("Jannis");

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
    cT1.highFivesGuys();
}