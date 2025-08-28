#include "Cat.hpp"

Cat::Cat() : Animal(){
    _type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(){
    _type = other._type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Cat purrs on your lap" << std::endl;
}