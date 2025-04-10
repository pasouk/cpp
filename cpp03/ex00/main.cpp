#include "ClapTrap.hpp"


int main() {
    
    //creation of a robot and printing inital values
    ClapTrap robot("Jean-rene");
    std::cout << "Initial values - Name: " << robot.getname() << ", HP: " << robot.getHitPoints() << ", Energy: " << robot.getEnergyPoints() << ", Attack Damage: " << robot.getAttackDamage() << std::endl;

    //robot attacks until he doesnt have hitpoints or Energypoints anymore
    while (robot.getHitPoints() > 0 && robot.getEnergyPoints() > 0) {
        std::cout << "\n--- New attack ---\n";
        robot.attack("Target");
        int damage = 2;
        robot.takeDamage(damage);
        robot.beRepaired(2);
    }

    //Robot tries to attack when he cannot
    std::cout << std::endl << std::endl << "robot tries to attak without life " << std::endl;
    robot.attack("Target");
    std::cout << std::endl << std::endl;


    //test if we dont give a name
    ClapTrap unknown_robot;
    std::cout << "Robot without given name is called " << unknown_robot.getname() << std::endl << std::endl;

    //test of the copy constructor
    ClapTrap copied_robot(robot);
    std::cout << "Robot copied is called  " << copied_robot.getname() << std::endl << std::endl;

    return 0;
}