#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>

class Zombie {
    private:
        std::string _name;
    public:
        void announce( void );
};

#endif