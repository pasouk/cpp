#include "Span.hpp"
#include <cstdlib> 
#include <ctime>   

int main()
{
    std::srand(static_cast<unsigned>(std::time(NULL)));
    std::cout << "span de 0\n";
    {
        Span z_test(0);
        try 
        {
            z_test.addNumber(1);
        } 
        catch (const std::exception &e) 
        {
            std::cerr << " addNumber : " << e.what() << std::endl;
        }

        try {
            z_test.longuestSpan();
        } catch (const std::exception &e) {
            std::cerr << "z_test longuestSpan : " << e.what() << std::endl;
        }

        try {
            z_test.shortestSpan();
        } catch (const std::exception &e) 
        {
            std::cerr << "z_test shortestSpan : " << e.what() << std::endl;
        }
    }
    std::cout << std::endl << "-----------------------------------------------------" << std::endl; 
    std::cout << "Span de 5\n";
    {
        Span test(5);
        try 
        {
            test.addNumber(1);
            test.addNumber(6);
            test.addNumber(19);
            test.addNumber(4);
            test.addNumber(8);
            test.addNumber(10); // Doit throw une exception
        } 
        catch (const std::exception &e) 
        {
            std::cerr << "ajout : " << e.what() << std::endl;
        }

        try 
        {
            std::cout << " longest : " << test.longuestSpan() << std::endl;
            std::cout << " shortest : " << test.shortestSpan() << std::endl;
        } catch (const std::exception &e) 
        {
            std::cerr << " calculs : " << e.what() << std::endl;
        }
    }
std::cout << std::endl << "-----------------------------------------------------" << std::endl; 
  std::cout << "Grand span : \n" << std::endl;
    // ajout  avec addNumbers 
    {
        unsigned int size = 100;
        Span big(size);

        std::vector<int> vec_rand;
        for (unsigned int i = 0; i < size; ++i) 
        {
            int nb = std::rand() % 1000;
            vec_rand.push_back(nb);
            //std::cout << nb << " added to random vect " << std::endl;
        }

        try 
        {
            big.addNumbers(vec_rand.begin(), vec_rand.end()); 
        } 
        catch (const std::exception &e) 
        {
            std::cerr << " ajout massif : " << e.what() << std::endl;
        }

        try 
        {
            std::cout << " longest : " << big.longuestSpan() << std::endl;
            std::cout << "shortest : " << big.shortestSpan() << std::endl;
        } 
        catch (const std::exception &e) 
        {
            std::cerr << " calculs : " << e.what() << std::endl;
        }
    }

    return 0;
}