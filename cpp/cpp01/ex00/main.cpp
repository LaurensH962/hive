#include "Zombie.hpp"

int main( void )
{
    Zombie *z = newZombie("SalatGurke");
    z->announce();
    randomChump("KarottenSaft");
    delete z;
}