#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

const int SIZE = 10;

// this is not possible anymore since Aimal is abstract. uncomment to test

// void testAnimal(){
//     Animal frog("dartfrog");
//     Animal toad(frog);
//     Animal tadpole = frog;
//     frog.makeSound();
//     toad.makeSound();
//     tadpole.makeSound();
//     return ;
// }

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

void testBrain() {
    std::cout << "=== Brain Tests ===" << std::endl;

    Brain b1;
    b1.setIdea(0, "I want food");
    b1.setIdea(1, "I want sleep");

    std::cout << "b1[0] = " << b1.getIdea(0) << std::endl;
    std::cout << "b1[1] = " << b1.getIdea(1) << std::endl;

    Brain b2(b1);
    std::cout << "b2[0] = " << b2.getIdea(0) << std::endl;

    Brain b3;
    b3 = b1;
    std::cout << "b3[1] = " << b3.getIdea(1) << std::endl;

    b1.setIdea(0, "New idea in b1");

    std::cout << "After changing b1[0]:" << std::endl;
    std::cout << "b1[0] = " << b1.getIdea(0) << std::endl;
    std::cout << "b2[0] = " << b2.getIdea(0) << std::endl;
    std::cout << "b3[0] = " << b3.getIdea(0) << std::endl;

    std::cout << "=== return from Brain Tests ===" << std::endl;
}

int main()
{
    testBrain();
    //testAnimal(); not working anymore because abstract class --> intended
    testCat();
    testDog();

    std::cout << "\n=== test base classes with new ===\n" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
    std::cout << "\n=== start main function ===" << std::endl;

    Animal* animals[SIZE];
    for (int i = 0; i < SIZE / 2; i++)
        animals[i] = new Cat();
    for (int i = SIZE / 2; i < SIZE; i++)
        animals[i] = new Dog();
    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();
    for (int i = 0; i < SIZE; i++)
        delete animals[i];
    return 0;
}