#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name_str, Weapon &wpn) : weapon(wpn), name(name_str)
{

}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

