#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    _type = "Dog";
    _brain = new (Brain);
}

Dog::Dog(const Dog& other) : Animal(){
    std::cout << "Dog copy constructor called" << std::endl;
    _type = other._type;
}

Dog& Dog::operator=(const Dog& other){
    std::cout << "Dog copy assignment constructor called" << std::endl;
    if(this != &other){
        this->_type = other._type;
    }
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

void Dog::makeSound() const{
    std::cout << "Dog munches loudly on a treat" << std::endl;
}