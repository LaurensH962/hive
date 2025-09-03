#include "Cat.hpp"

Cat::Cat() : Animal(){
    std::cout << "Cat default constructor called" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(){
    std::cout << "Cat copy constructor called" << std::endl;
    _type = other._type;
    _brain = new Brain(*other._brain); 
}

Cat& Cat::operator=(const Cat& other){
    std::cout << "Cat copy assignment constructor called" << std::endl;
    if(this != &other){
        Animal::operator=(other);  
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain); 
    }
    return *this;
}

Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

void Cat::makeSound() const{
    std::cout << "Cat purrs on your lap" << std::endl;
}