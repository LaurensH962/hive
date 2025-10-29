#include "Base.hpp"

int main (void){
    srand(time(NULL));
    Base* ptr = generate();
    identify(ptr);
    identify(*ptr);
    if (ptr != nullptr)
        delete ptr;
}