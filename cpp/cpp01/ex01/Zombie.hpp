#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

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

#endif