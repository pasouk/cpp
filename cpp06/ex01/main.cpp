#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data original;
    original.number = 1337;
    original.letter = 'X';

    std::cout << "Original Data address: " << &original << std::endl;
    std::cout << "Original Data number: " << original.number << std::endl;
    std::cout << "Original Data letter: " << original.letter << std::endl;

    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << deserialized << std::endl;
    std::cout << "Deserialized Data number: " << deserialized->number << std::endl;
    std::cout << "Deserialized Data letter: " << deserialized->letter << std::endl;

    if (deserialized == &original)
        std::cout << "Conversion OK !" << std::endl;
    else
        std::cout << "Erreur de conversion." << std::endl;

    return 0;
}