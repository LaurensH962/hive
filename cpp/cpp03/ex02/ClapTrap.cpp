#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :  _hitPoints(10), 
                        _energyPoints(10), 
                        _attackDamage(0) {
    std::cout << C_BLUE << "Clap Trap default constructor has been called" << C_RESET << std::endl;
};


ClapTrap::ClapTrap(std::string name) :  _name(name), 
                                        _hitPoints(10),
                                        _energyPoints(10),
                                        _attackDamage(0) {
    std::cout << C_BLUE << "Clap Trap constructor has been called" << C_RESET << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name),
                                            _hitPoints(other._hitPoints),  
                                            _energyPoints(other._energyPoints),
                                            _attackDamage(other._attackDamage) {
    std::cout << C_BLUE << "Clap Trap copy constructor has been called" << C_RESET << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << C_BLUE << "Clap Trap Destructor has been called" << C_RESET << std::endl;
}

void ClapTrap::attack(const std::string& target){
    _energyPoints --;
    if (_energyPoints <  0 ){
        std::cout << C_BLUE   << "ClapTrap "  << _name
                    << " does not have enough energy points to attack" << C_RESET << std::endl;
        return ;
    }
    std::cout   << C_BLUE << "ClapTrap "  << _name
                << " attacks " << target
                << " causing " << _attackDamage
                << "points of damage!"
                << ". New energy points are: " << _energyPoints << C_RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (_hitPoints <= 0){
        std::cout   << C_BLUE  << "ClapTrap "  << _name
                    << " is already dead." << C_RESET << std::endl;
        return ;
    }
    _hitPoints -= amount;
    if (_hitPoints <= 0){
        std::cout   << C_BLUE   << "ClapTrap "  << _name
                    << " is dead." << C_RESET << std::endl;
        return ;
    }
    std::cout   << C_BLUE   << "ClapTrap "  << _name
                << " takes " << amount << " damage." 
                << " Remaining hitpoints are: " << _hitPoints << C_RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    _energyPoints --;
    if (_energyPoints <  0){
        std::cout   << C_BLUE  << "ClapTrap "  << _name
                    << " does not have enough energy points to repair itself" << C_RESET << std::endl;
        return ;
    }
    if (_hitPoints <=  0){
    std::cout   << C_BLUE   << "ClapTrap "  << _name
                << " is dead and cannot repair itself" << C_RESET << std::endl;
    return ;
    }
    _hitPoints += amount;
    std::cout   << C_BLUE   << "ClapTrap "  << _name
                << " reapairs itself by " << amount << "." 
                << " New hitpoints are: " << _hitPoints 
                << ". New energy points are: " << _energyPoints << C_RESET << std::endl;
}