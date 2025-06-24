#include "Span.hpp"

int main()
{
    Span test(5);
    test.addNumber(1);
    //test.addNumber(1);
    //test.addNumber(1);
    //test.addNumber(1);
    //test.addNumber(1);
    //test.addNumber(10);
    
    int longuest = test.longuestSpan();
    std::cout << longuest;
}