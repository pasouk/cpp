
#include "Form.hpp"

int main()
{
    std::cout << "----- TEST FORM CREATION -----" << std::endl;

    try 
    {
        Form f1("FormA", 50, 100);
        std::cout << f1 << std::endl;

        Form f2("FormB", 0, 100); // Trop haut 
         std::cout << f2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    try
    {
        Form f3("FormC", 50, 151); // Trop bas 
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }




    std::cout << "\n---- TEST BE SIGNED -----" << std::endl;

    try
    {
        Bureaucrat b1("Alice", 45);
        Form f4("ImportantForm", 50, 100);
        std::cout << b1 << std::endl;
        std::cout << f4 << std::endl;

        f4.beSigned(b1); 
        std::cout << "( Alice a le grade 45, peut signer un form de 50 )" << std::endl;
        std::cout << f4 << std::endl;

        Bureaucrat b2("Bob", 60);
        Form f5("SecretForm", 50, 100);
        std::cout << b2 << std::endl;
        std::cout << "(  Bob a le grade 60:  trop bas pour signer un form à 50 )" << std::endl;
        f5.beSigned(b2);
    }
    catch (const std::exception &e) 
    {
        std::cout << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }



    std::cout << "\n----- TEST SIGNFORM -----" << std::endl;

    try
    {
        Bureaucrat c1("Charlie", 40);
        Form f6("TopSecretForm", 30, 50);
        std::cout << "devrait échouer car Charlie a grade 40 < 30" << std::endl;
        c1.signForm(f6);

        Bureaucrat c2("Diana", 25);
        std::cout << "devrait réussir car Diana a grade 25 < 30" << std::endl;
        c2.signForm(f6);

    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

}