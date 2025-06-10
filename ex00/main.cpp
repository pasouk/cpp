#include "Bureaucrat.hpp"

int main()
{
    std::cout << "----------- TEST CONSTRUCTEURS ----------" << std::endl;
    try {
        Bureaucrat b1;
        std::cout << b1 << std::endl;

        Bureaucrat b2("Alice");
        std::cout << b2 << std::endl;

        Bureaucrat b3("Bob", 42);
        std::cout << b3 << std::endl;

        Bureaucrat b4(100);
        std::cout << b4 << std::endl;

        //cp constr
        Bureaucrat b5(b3);
        std::cout << b5 << std::endl;

        // Test grade trop haut
        Bureaucrat b6("InvalidHigh", 0);
    }
    catch (const std::exception &e) 
    {
        std::cout << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    // Test grade trop bas
    try
    {        
        Bureaucrat b7("InvalidLow", 151);
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }



    std::cout << std::endl << "------------------TEST INCREMENT / DECREMENT -------------------" << std::endl;
    try 
    {
        Bureaucrat b8("Clara", 2);
        std::cout << b8 << std::endl;
        std::cout << "clara a " << b8.getGrade() << " et on incremente : " << std::endl;
        b8.incrementGrade();
        std::cout << b8 << std::endl;
        std::cout << "clara a " << b8.getGrade() << " et on incremente : " << std::endl;
        b8.incrementGrade();
        std::cout << "clara a " << b8.getGrade() << std::endl;
    }
    catch (const std::exception &e) 
    {
        std::cout << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    try 
    {
        Bureaucrat b9("David", 149);
        std::cout << b9 << std::endl;
        std::cout << "David a " << b9.getGrade() << " et on decremente : " << std::endl;
        b9.decrementGrade();
        std::cout << "David a " << b9.getGrade() << " et on decremente : " << std::endl;
        std::cout << b9 << std::endl;
        b9.decrementGrade();
    }
    catch (const std::exception &e) 
    {
        std::cout << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}