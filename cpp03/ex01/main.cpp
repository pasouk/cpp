#include "ScavTrap.hpp"

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

int main() 
{
    //creation of a robot and printing inital values
    ScavTrap robot("Jean-Luc");
    std::cout << "Initial values - Name: " << robot.getName() << ", HP: " << robot.getHitPoints() << ", Energy: " << robot.getEnergyPoints() << ", Attack Damage: " << robot.getAttackDamage() << std::endl;



    //robot attacks until he doesnt have hitpoints or Energypoints anymore
    while (robot.getHitPoints() > 0 && robot.getEnergyPoints() > 0) {
        std::cout << "\n--- New attack ---\n";
        robot.attack("Target");
        int damage = 2;
        robot.takeDamage(damage);
        robot.beRepaired(2);
    }

    //Robot tries to attack when he cannot
    std::cout << std::endl << std::endl << "--robot tries to attak without life --" << std::endl;
    robot.attack("Target");
    std::cout << std::endl << std::endl;


    //test if we dont give a name
    ScavTrap unknown_robot;
    std::cout << "Robot without given name is called " << unknown_robot.getName() << std::endl << std::endl;

    //test of the copy constructor
    ScavTrap copied_robot(robot);
    std::cout << "Robot copied is called  " << copied_robot.getName() << std::endl << std::endl;

    //gate keeper test
    std::cout << "\n--- Calling guard gate 3 times ---\n";
    robot.guardGate();
    robot.guardGate();
    robot.guardGate();
    std::cout << std::endl << std::endl;

    return 0;

}
