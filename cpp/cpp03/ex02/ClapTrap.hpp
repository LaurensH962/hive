#pragma once

#include <iostream>

#define C_RESET   "\033[0m"
#define C_RED         "\033[31m"
#define C_GREEN       "\033[32m"
#define C_BLUE        "\033[34m"

class ClapTrap{
    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other) = delete;
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
