#ifndef FRAGTRAP_CPP
#define FRAGTRAP_CPP

#include "ClapTrap.hpp"

class FragTrap:public ClapTrap 
{
    private:

    public:
    
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &other);
    ~FragTrap();

    FragTrap &operator=(const FragTrap &other);

    void attack(const std::string& target);
    void highFivesGuys(void);


    
};

#endif
