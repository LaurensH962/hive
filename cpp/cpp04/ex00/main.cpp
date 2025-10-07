#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


void testAnimal(){
    Animal frog("dartfrog");
    Animal toad(frog);
    Animal tadpole = frog;
    frog.makeSound();
    toad.makeSound();
    tadpole.makeSound();
    return ;
}

void testWrongCat(){
    std::cout << "-- wrong cat as animal --" << std::endl;
    const WrongAnimal* wrong = new WrongCat();
    wrong->makeSound();
    delete wrong;

    std::cout << "-- now actual wrong cat --" << std::endl;
    WrongCat wCAT;
    wCAT.makeSound();
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
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    testAnimal();
    testCat();
    testDog();
    testWrongCat();
    return 0;
}