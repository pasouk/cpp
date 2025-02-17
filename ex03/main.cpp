#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}

/*
    les avantages du pointeur : 
    L'objet Weapon peut etre absent au moment de l'initialisation 
    On peut changer l objet pointé (ex si  pplusieurs armes)
    Avec une reference il n'est pas possible de ne pas avoir d'arme (pointeur : via nullptr (seulement cpp 11))


    Avec la ref: 

    Si l'objet Weapon doit toujours être présent et ne jamais être nul, une référence est plus sûre. 
    On peut assigner des le debut (constructeur )
    si l objet ne doit pas etre reassigné apres la construction (empeche reassign accidentelle)
    plus simple car ne requiert pas de vérif de nullité ou d'opérateurs spécifiques

    Résumé :
            	                    Pointeur	                     Référence
    Peut être nul	                ✅ Oui	                        ❌ Non
    Initialisation obligatoire	    ❌ Non	                        ✅ Oui
    Peut être réassigné	            ✅ Oui	                        ❌ Non
    Manipulation simple	            ❌ Nécessite -> et vérif.	    ✅ Accès direct avec .
    Dynamisme et flexibilité    	✅ Utile pour changement    	    ❌ Fixe après assignation
*/