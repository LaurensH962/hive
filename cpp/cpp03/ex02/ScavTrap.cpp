#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout   << C_RED << "Scav Trap default constructor has been called" << C_RESET << std::endl;
    _hitPoints = 100;
    _attackDamage = 20;
    _energyPoints = 50;
}

ScavTrap::ScavTrap(std::string name){
    std::cout   << C_RED << "Scav Trap constructor has been called" << C_RESET << std::endl;
    _name = name;
    _hitPoints = 100;
    _attackDamage = 20;
    _energyPoints = 50;
}

ScavTrap::ScavTrap(const ScavTrap& other) :ClapTrap(other){
    std::cout   << C_RED << "Scav Trap copy constructor has been called" << C_RESET << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout   << C_RED << "Scav Trap destructor has been called" << C_RESET << std::endl;
}

void ScavTrap::guardGate(){
    if (_hitPoints <= 0 || _energyPoints <= 0){
        std::cout   << C_RED   << "ScavTrap " << _name
                << " cannot switch into guard gate mode."<< C_RESET  << std::endl;
    }
    std::cout   << C_RED   << "ScavTrap " << _name
                << " is in guard gate mode." << C_RESET << std::endl;
}

void ScavTrap::attack(const std::string& target){
    _energyPoints --;
    if (_energyPoints <  0 ){
        std::cout   << C_RED   << "ScavTrap "  << _name
                    << " does not have enough energy points to attack" << C_RESET << std::endl;
        return ;
    }
    std::cout   << C_RED   << "ScavTrap "  << _name
                << " attacks " << target
                << " causing " << _attackDamage
                << "points of damage!"
                << ". New energy points are: " << _energyPoints << C_RESET << std::endl;
}