#ifndef HUMANB_CPP
#define HUMANB_CPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class   HumanB
{
private:
    Weapon *weapon ;
    std::string name;

public:
    HumanB(std::string name_str);
    void setWeapon(Weapon &wpn);
    void attack();


};

#endif