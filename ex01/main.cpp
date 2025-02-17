#include "Zombie.hpp"

int main()
{
    Zombie *Zombies = zombieHorde(10, "Pierre-Etienne");

    for(int i = 0; i < 10; i++)
    {
        Zombies[i].announce(); 
    }

    delete[] Zombies;
}