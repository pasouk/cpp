#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name("Unknown"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor has been called\n";
}

ClapTrap::ClapTrap(std::string name):name(name), hitPoints(10), 
energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor has been called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "ClapTrap copy constructor has been called\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor has been called\n";
}


void ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    { 
        std::cout << "ClapTrap " << name <<  " attacks " << target;   
        std::cout << ", causing " << attackDamage << " points of damage! " << std::endl;
        energyPoints --;
    }
    else 
    {
        std::cout << "ClapTrap " << name << " cannot attack for now... " << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already destroyed and cannot take more damage! " << std::endl;
        return;
    }

    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;

    std::cout << "ClapTrap " << name << " takes " << amount;
    std::cout << " points of damage! Remaining HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints != 0 && hitPoints != 0)
    {
        std::cout << "ClapTrap " << name <<  " gets " << amount;   
        std::cout << " hits points back " << std::endl;
        energyPoints --;
        hitPoints = hitPoints + amount;
    }
    else 
    {
        std::cout << "ClapTrap " << name << " cannot be repaired for now... " << std::endl;
    }
}



std::string ClapTrap::getname()
{
    return name; 
}

int ClapTrap::getHitPoints()
{
    return hitPoints;
}

int ClapTrap::getEnergyPoints()
{
    return energyPoints;
}

int ClapTrap::getAttackDamage()
{
    return attackDamage;
}

void ClapTrap::setName(std::string str)
{
    name = str;
}

void ClapTrap::setHitPoints(int nb)
{
    hitPoints = nb;
}

void ClapTrap::setEnergyPoints(int nb)
{
    energyPoints = nb;
}

void ClapTrap::setAttackDamage(int nb)
{
    attackDamage = nb;
}