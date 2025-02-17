#include "Zombie.hpp"

int main()
{
    //allocation sur la stack, (automatique), on est obligé d'utiliser announce dans la fonction
    //l´objet est automatiquement détruit (destroctor utilisé) a la fin de la fonction
    randomChump("stackman");
    
    //sallocation sur la heap: on peut utiliser le zombie créé en dohors de la fonction, 
    //il est alloue manuellement, et doit donc etre libéré
    Zombie *test_heap;
    test_heap = newZombie("heapman");
    test_heap->announce();

    //détruire heapman
    delete test_heap;
}