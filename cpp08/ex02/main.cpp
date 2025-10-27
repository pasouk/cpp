#include "MutantStack.hpp"
#include <string>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
   //mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Au début, it pointe sur : " << *it << std::endl;
    std::cout << "Au début, ite pointe sur : " << *ite << std::endl;
    ++it;
    --ite;
    std::cout << "Après ++it : " << *it << std::endl;
    std::cout << "Après --ite : " << *ite << std::endl;
    --it;
    ++ite;
    std::cout << "Après --it : " << *it << std::endl;
    std::cout << "Après ++ite : " << *ite << std::endl;

    std::cout << "\nMutantStack :" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}
