#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
    std::cout << "Give me five ! \n";
}

FragTrap::FragTrap() : ClapTrap(100, 100, 30)
{
    std::cout << "FragTrap constructor has been called\n";
}


FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap constructor has been called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor has been called\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor has been called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this == &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap assignment operator called\n";
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (getEnergyPoints() != 0 && getHitPoints() != 0)
    {
        std::cout << "FragTrap " << getName() <<  " attacks " << target;   
        std::cout << ", causing " << getAttackDamage() << " points of damage! " << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
    }
    else 
    {
        std::cout << "FragTrap " << getName() << " cannot attack for now... " << std::endl;
    }
}