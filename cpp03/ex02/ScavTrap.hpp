#ifndef SCAVTRAP_CPP
#define SCAVTRAP_CPP

#include "ClapTrap.hpp"

class ScavTrap:public ClapTrap 
{
    private:
    bool gate_keeper;

    public:
    
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ~ScavTrap();

    ScavTrap &operator=(const ScavTrap &other);

    void attack(const std::string& target);
    void guardGate();



    
};





#endif
