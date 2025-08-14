#include "Zombie.hpp"

int main( void )
{
    Zombie *z = newZombie("Gherkin");
    z->announce();
    randomChump("Pickle");
    delete z;
}