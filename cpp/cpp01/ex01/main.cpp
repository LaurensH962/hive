#include "Zombie.hpp"

int main( void )
{
    int N = 5;
    Zombie *z = zombieHorde(N, "SalatGurke");
    for (int i; i < N; i++)
        z[i].announce();
    delete[] z;
}