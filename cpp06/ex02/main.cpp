#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
    int n = 1 + std::rand() % 3;

    if (n == 1)
        return new A;
    else if (n == 2)
        return new B;
    else
        return new C;
}


void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } 
    catch (...) 
    {

    }

    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } 
    catch (...)
    {

    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } 
    catch (...) 
    {

    }
}

//dynamic_cast<A*>(p) retourne le pointeur converti si l’objet pointé est de type A (ou dérivé de A)    sinon  ----> null
//dynamic_cast<A&>(p) tente de caster P en a et si cela echoue il retourne une exception


// Nécessite un destructeur virtuel dans Base pour activer le RTTI (Run Time Type Information)
// car si une  classe n’a aucune fonction virtuelle, elle n’a pas de vtable → et donc pas de RTTI (Run Time Type Information) 
// -------> et donc pas de dynamic_cast possible.

int main()
{
    std::srand(std::time(0));

    Base* obj = generate();

    std::cout << "Identify by pointer : ";
    identify(obj);

    std::cout << "Identify by reference : ";
    identify(*obj);

    
    delete obj;

    return 0;
}