#pragma once

#include <iostream>

class Animal{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &other);
        Animal& operator=(const Animal& other) = delete;
        virtual ~Animal();
        virtual void makeSound() const;
        virtual std::string getType() const;
};