#ifndef HUMANA_CPP
#define HUMANA_CPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class   HumanA
{
private:
    Weapon &weapon;
    std::string name;

public:
    HumanA(std::string name_str, Weapon &wpn);
    void attack();
};

#endif