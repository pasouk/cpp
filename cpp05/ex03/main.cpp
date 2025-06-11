#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern  someIntern;

        AForm* form1 = someIntern.makeForm("PresidentialPardonForm", "PresiTest");
        AForm* form2 = someIntern.makeForm("RobotomyRequestForm", "RequestTest");
        AForm* form3 = someIntern.makeForm("ShrubberyCreationForm", "CreationTest");
        AForm* form4 = someIntern.makeForm("InexistantForm", "NoForm");
        std::cout << std::endl;

        Bureaucrat michel("Michel", 1);
        Bureaucrat jean("Jean", 149);
        std::cout << std::endl;

        // Signature et exécution des form
        michel.signForm(*form1);
        michel.executeForm(*form1);
        std::cout << std::endl;

        michel.signForm(*form2);
        michel.executeForm(*form2);
        std::cout << std::endl;

        jean.signForm(*form3); // Trop bas pour signer
        michel.signForm(*form3);
        jean.executeForm(*form3); // Trop bas pour exécuter
        michel.executeForm(*form3);

        std::cout << std::endl;


        delete form1;
        delete form2;
        delete form3;
        delete form4; 

    }
    catch (const std::exception &e)
    {
        std::cerr << "Erreur attrapée : " << e.what() << std::endl;
    }

    return 0;
}