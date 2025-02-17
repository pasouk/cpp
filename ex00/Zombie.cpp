#include "Zombie.hpp"

void Zombie::setName(std::string str)
{
    name = str;
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " has been destroyed." << std::endl;
}