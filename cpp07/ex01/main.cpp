#include "iter.hpp"

int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ::iter(array, 10, displayMe);

    std::string arrayb[5] = {"ciao", "come", "stai", "oggi", "?"};
    ::iter(arrayb, 5, displayMe);

    float arrayc[10] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.10, 10.11};
    ::iter(arrayc, 10, displayMe);
}