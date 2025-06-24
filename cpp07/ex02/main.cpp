#include <iostream>
#include "Array.hpp"

int main() {
    // Test tableau vide
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;

    // Test tableau de strings
    Array<std::string> b(5);
    b[0] = "Hello";
    b[1] = "from";
    b[2] = "Array";
    b[3] = "template";
    b[4] = "class";

    std::cout << "\nContenu de b :" << std::endl;
    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    // Test constructeur de copie
    Array<std::string> c(b);
    c[0] = "Hi";
    std::cout << "\nAprès modification de c[0] = 'Hi' :" << std::endl;
    std::cout << "b[0] = " << b[0] << " (original)" << std::endl;
    std::cout << "c[0] = " << c[0] << " (copie)" << std::endl;

    // Test opérateur d'affectation
    Array<std::string> d;
    d = b;
    std::cout << "\nContenu de d après affectation :" << std::endl;
    for (unsigned int i = 0; i < d.size(); ++i)
        std::cout << "d[" << i << "] = " << d[i] << std::endl;

    // Test exception si index hors limite
    try {
        std::cout << "\nTentative d'accès hors limites à d[10] :" << std::endl;
        std::cout << d[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }

    return 0;
}