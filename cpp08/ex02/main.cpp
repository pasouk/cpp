#include "MutantStack.hpp"
#include <string>

void printSeparator(const std::string &title)
{
    std::cout << "\n----- " << title << "-----" << std::endl;
}

int main()
{
    printSeparator("Création d'une MutantStack<int>");
    MutantStack<int> mstack;

    printSeparator("Ajout éléments");
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top : " << mstack.top() << std::endl;

    printSeparator("Suppression du top");
    mstack.pop();
    std::cout << "size après pop : " << mstack.size() << std::endl;

    printSeparator("Ajout éléments");
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    printSeparator("tous les els");
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    for (; it != ite; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    printSeparator("Test copi constr");
    MutantStack<int> mstackCopy(mstack);
    std::cout << "Éléments de la copie : ";
    for (MutantStack<int>::iterator cit = mstackCopy.begin(); cit != mstackCopy.end(); ++cit)
        std::cout << *cit << " ";
    std::cout << std::endl;

    printSeparator("Test opérateur d'affectation");
    MutantStack<int> mstackAssign;
    mstackAssign = mstackCopy;
    std::cout << "après affectation : ";
    for (MutantStack<int>::iterator ait = mstackAssign.begin(); ait != mstackAssign.end(); ++ait)
        std::cout << *ait << " ";
    std::cout << std::endl;

    printSeparator("pile vide");
    MutantStack<int> emptyStack;
    std::cout << "Taille : " << emptyStack.size() << std::endl;
    if (emptyStack.begin() == emptyStack.end())
        std::cout << "Pile vide, aucune itération possible" << std::endl;

    printSeparator("Conv en std::stack");
    std::stack<int> s(mstack);
    std::cout << "Top de la std::stack copiée : " << s.top() << std::endl;

    return 0;
}