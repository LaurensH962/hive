#include "Base.hpp"
#include <time.h>
#include <iostream>

Base* generate(void){
    int chooseABC = std::rand() % 3;
    switch (chooseABC)
    {
    case 0:
        std::cout << "Generated A" << std::endl;
        return new A();
    case 1:
        std::cout << "Generated B" << std::endl;
        return new B();
    case 2:
        std::cout << "Generated C" << std::endl;
        return new C();
    default:
        return nullptr;
    }
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown base type" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}
    std::cout << "Unknown type" << std::endl;
}

int main (void){
    srand(time(NULL));
    Base* ptr = generate();
    identify(ptr);
    identify(*ptr);
    if (ptr != nullptr)
        delete ptr;
}