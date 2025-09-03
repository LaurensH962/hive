#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(){
    std::cout << "Dog copy constructor called" << std::endl;
    _type = other._type;
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other){
    std::cout << "Dog copy assignment constructor called" << std::endl;
    if(this != &other){
        Animal::operator=(other);
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain);
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