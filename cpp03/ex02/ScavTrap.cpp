#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
    if(gate_keeper == 1)
    {
        gate_keeper = 0;
        std::cout << getName() << " is no longer in gate keeper mode !" << std::endl ;
    }
    else
    {
        gate_keeper = 1;
        std::cout << getName() << " is now in gate keeper mode !" << std::endl ;

    }
}

ScavTrap::ScavTrap() : ClapTrap(100, 50, 20)
{
    std::cout << "ScavTrap constructor has been called\n";
}


ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
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

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this == &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap assignment operator called\n";
    gate_keeper = other.gate_keeper;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (getEnergyPoints() != 0 && getHitPoints() != 0)
    {
        std::cout << "ScavTrap " << getName() <<  " attacks " << target;   
        std::cout << ", causing " << getAttackDamage() << " points of damage! " << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
    }
    else 
    {
        std::cout << "ScavTrap " << getName() << " cannot attack for now... " << std::endl;
    }
}

// Note pour plus tard : on aurait pu déclarer attack avec le mot-clé virtual dans ClapTrap
// pour déclencher le polymorphisme. Cela permet au programme d'utiliser automatiquement
// la bonne version de attack en fonction du type réel de l'objet, peu importe le type du pointeur.

// Par exemple, si attack est déclarée virtual dans ClapTrap :
// ClapTrap* robot = new ScavTrap();
// Le mot-clé virtual permet à C++ de détecter que l'objet pointé est un ScavTrap,
// donc c'est ScavTrap::attack qui est appelée automatiquement,
// même si le pointeur est de type ClapTrap*.

// Dans mon cas (sans virtual), le polymorphisme n'est pas activé.
// Donc je suis obligé d'utiliser un pointeur de type ScavTrap* :
// ScavTrap* robot = new ScavTrap();
// Ce qui appelle bien ScavTrap::attack, mais sans le mécanisme de polymorphisme.