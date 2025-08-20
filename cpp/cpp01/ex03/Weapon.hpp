#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "string"

class Weapon{
    private:
        std::string _type;
    public:
        Weapon(std::string type) : _type(type){};
        const std::string& getType() const;
        void setType(const std::string& type);
};

#endif