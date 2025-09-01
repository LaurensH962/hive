#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

const int SIZE = 10;

void testAnimal(){
    Animal frog("dartfrog");
    Animal toad(frog);
    Animal tadpole = frog;
    frog.makeSound();
    toad.makeSound();
    tadpole.makeSound();
    return ;
}

void testCat(){
    Cat tiger;
    Cat tigress(tiger);
    Cat babytiger = tiger;
    tiger.makeSound();
    tigress.makeSound();
    babytiger.makeSound();
    return ;
}

void testDog(){
    Dog wolf;
    Dog chihuahua(wolf);
    Dog lamb = wolf;
    wolf.makeSound();
    chihuahua.makeSound();
    lamb.makeSound();
    return ;
}

int main()
{
    testAnimal();
    testCat();
    testDog();
    Animal* animals[SIZE];
    for (int i = 0; i < SIZE / 2; ++i)
        animals[i] = new Cat();
    for (int i = SIZE / 2; i < SIZE; ++i)
        animals[i] = new Cat();
    for (int i = 0; i < SIZE; ++i)
        animals[i]->makeSound();
    for (int i = 0; i < SIZE; ++i)
        delete animals[i];
    return 0;
}