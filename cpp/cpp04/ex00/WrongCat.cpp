#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
    _type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(){
    _type = other._type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called" << std::endl;
}
