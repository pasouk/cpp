#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombies = new Zombie[N];
    for(int i = 0; i < N; i++)
    {
        zombies[i].setName(name);
        std::cout << name << " number " << i + 1 << " was created" << std::endl;
    }
    return (zombies);
}