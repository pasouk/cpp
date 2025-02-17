#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name_str) : name(name_str)
{

}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &wpn)
{
    this->weapon = &wpn;
}