#include "whatever.hpp"

int main()
{
    int a = 4;
    int b = 2;

    std::cout << "initially a is " << a << " and b is " << b << std::endl;
    ::swap(a, b);
    std::cout << "aftrer swap a is " << a << " and b is " << b << std::endl;
    std::cout << "So min is " << ::min(a, b) << " and max is " << ::max(a, b) << std::endl;
    std::cout << "----------------------------------------------------------------------- \n";

    std::string c = "Ciao";
    std::string d = "Hola";
    std::cout << "initially a is " << c << " and b is " << d << std::endl;
    ::swap(c, d);
    std::cout << "aftrer swap a is " << c << " and b is " << d << std::endl;
    std::cout << "So min is " << ::min(c, d) << " and max is " << ::max(c, d) << std::endl;
    std::cout << "----------------------------------------------------------------------- \n";


    float e = 2.4;
    float f = 2.42;

    std::cout << "initially a is " << e << " and b is " << f << std::endl;
    ::swap(e, f);
    std::cout << "aftrer swap a is " << e << " and b is " << f << std::endl;
    std::cout << "So min is " << ::min(e, f) << " and max is " << ::max(e, f) << std::endl;
    std::cout << "----------------------------------------------------------------------- \n";

    
    
    
    return 0;
}
/*
int main( void )
 { int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0; }*/