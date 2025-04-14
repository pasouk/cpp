#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
    protected:
    std::string     name;
    int             hitPoints;
    int             energyPoints;
    int             attackDamage;

    public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap(int hp, int ep, int ad);
    ClapTrap(std::string str, int hp, int ep, int ad);
    ~ClapTrap();

    ClapTrap operator=(const ClapTrap &other);

    std::string getName();
    int getHitPoints();
    int getEnergyPoints();
    int getAttackDamage();

    void setName(std::string name);
    void setHitPoints(int hitPoints);
    void setEnergyPoints(int energyPoints);
    void setAttackDamage(int attackDamage);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};









#endif