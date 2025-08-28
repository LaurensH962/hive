#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type){
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type){
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const{
    std::cout << "Animal makes sound" << std::endl;
}

std::string Animal::getType() const{
    return _type;
}