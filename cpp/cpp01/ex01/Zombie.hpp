#pragma once

#include <iostream>

class Zombie {
    private:
        std::string _name;
    public:
        Zombie(){}
        // Zombie(std::string name) : _name(name) {}
        void announce( void );
        void setName(std::string name) { _name = name; };
};

Zombie* zombieHorde( int N, std::string name );
