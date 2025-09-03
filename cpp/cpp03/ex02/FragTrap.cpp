#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout   << C_GREEN << "Frag Trap default constructor has been called" << C_RESET << std::endl;
    _hitPoints = 100;
    _attackDamage = 30;
    _energyPoints = 100;
}

FragTrap::FragTrap(std::string name){
    std::cout   << C_GREEN << "Frag Trap constructor has been called" << C_RESET << std::endl;
    _name = name;
    _hitPoints = 100;
    _attackDamage = 30;
    _energyPoints = 100;
}

FragTrap::FragTrap(const FragTrap& other) :ClapTrap(other){
    std::cout   << C_GREEN << "Frag Trap copy constructor has been called" << C_RESET << std::endl;
}

FragTrap::~FragTrap(){
    std::cout   << C_GREEN << "Frag Trap destructor has been called" << C_RESET << std::endl;
}

void FragTrap::highFivesGuys(void){
    if (_hitPoints <= 0 || _energyPoints <= 0){
        std::cout   << C_GREEN   << "FragTrap " << _name
                << " cannot give high fives anymore."<< C_RESET  << std::endl;
        return;
    }
    std::cout   << C_GREEN << "Frag Trap requests a delightful high five :)" << C_RESET << std::endl;
}