#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "Scav Trap default constructor has been called" << std::endl;
    _hitPoints = 100;
    _attackDamage = 20;
    _energyPoints = 50;
}

ScavTrap::ScavTrap(std::string name){
    std::cout << "Scav Trap constructor has been called" << std::endl;
    _name = name;
    _hitPoints = 100;
    _attackDamage = 20;
    _energyPoints = 50;
}

ScavTrap::ScavTrap(const ScavTrap& other) :ClapTrap(other){
    std::cout << "Scav Trap copy constructor has been called" << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "Scav Trap destructor has been called" << std::endl;
}

void ScavTrap::guardGate(){
    if (_hitPoints <= 0 || _energyPoints <= 0){
        std::cout   << "ScavTrap " << _name
                << " cannot switch into guard gate mode." << std::endl;
    }
    std::cout   << "ScavTrap " << _name
                << " is in guard gate mode." << std::endl;
}

void ScavTrap::attack(const std::string& target){
    _energyPoints --;
    if (_energyPoints <  0 ){
        std::cout   << "ScavTrap "  << _name
                    << " does not have enough energy points to attack" << std::endl;
        return ;
    }
    std::cout   << "ScavTrap "  << _name
                << " attacks " << target
                << " causing " << _attackDamage
                << "points of damage!"
                << ". New energy points are: " << _energyPoints << std::endl;
}