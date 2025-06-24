#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> testVector;
    std::list<int> testList;
    std::vector<int>::iterator itVector;
    std::list<int>::iterator itList;

    testVector.push_back(1);
    testVector.push_back(2);
    testVector.push_back(3);

    testList.push_back(7);
    testList.push_back(8);
    testList.push_back(9);

    //  2 dans vector
    itVector = easyfind(testVector, 2);
    if (itVector != testVector.end())
        std::cout << "Found in vector: " << *itVector << std::endl;
    else
        std::cout << "Not found in vector." << std::endl;

    // pas dans la liste
    itList = easyfind(testList, 2);
    if (itList != testList.end())
        std::cout << "Found in list: " << *itList << std::endl;
    else
        std::cout << "Not found in list." << std::endl;

    // 8 dans la liste
    itList = easyfind(testList, 8);
    if (itList != testList.end())
        std::cout << "Found in list: " << *itList << std::endl;
    else
        std::cout << "Not found in list." << std::endl;

    // cont vide
    std::vector<int> emptyVector;
    itVector = easyfind(emptyVector, 1);
    if (itVector != emptyVector.end())
        std::cout << "Found in empty vector: " << *itVector << std::endl;
    else
        std::cout << "Not found in empty vector." << std::endl;

    //pLUSIEURS OCCURRENCES
    std::vector<int> repeatedVector;
    repeatedVector.push_back(5);
    repeatedVector.push_back(2);
    repeatedVector.push_back(2);
    repeatedVector.push_back(3);

    itVector = easyfind(repeatedVector, 2);
    if (itVector != repeatedVector.end())
        std::cout << "Found in repeated vector: " << *itVector << std::endl;
    else
        std::cout << "Not found in repeated vector." << std::endl;
    std::cout << std::distance(repeatedVector.begin(), itVector);
    return 0;
}