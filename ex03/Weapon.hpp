#ifndef WEAPON_CPP
#define WEAPON_CPP

#include <iostream>
#include <string>

class   Weapon
{
private:
    std::string type;

public:
    Weapon(std::string str);
    const std::string &getType();
    void setType(std::string );
};

#endif