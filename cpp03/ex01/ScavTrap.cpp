#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);

    std::cout << "ScavTrap constructor has been called\n";
}


ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);

    std::cout << "ScavTrap constructor has been called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor has been called\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor has been called\n";
}


void ScavTrap::attack(const std::string& target)
{
    if (getEnergyPoints != 0 && getHitPoints != 0)
    {
        std::cout << "ScavTrap " << getName <<  " attacks " << target;   
        std::cout << ", causing " << getAttackDamage << " points of damage! " << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
    }
    else 
    {
        std::cout << "ScavTrap " << getName << " cannot attack for now... " << std::endl;
    }
}