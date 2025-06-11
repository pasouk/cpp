#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        // Création de bureaucrates
        Bureaucrat michel("Michel", 140);
        Bureaucrat sandra("Sandra", 45);
        Bureaucrat boss("Le Boss", 1);

        // Création de formulaires
        ShrubberyCreationForm shrub("SCHRUBTEST");
        RobotomyRequestForm robot("ROBOTTEST");
        PresidentialPardonForm pardon("PRDONTEST");

        // Test : Michel trop bas pour signer le PresidentialPardonForm
        try {
            michel.signForm(pardon);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        // Sandra signe ShrubberyCreationForm et RobotomyRequestForm
        try {
            sandra.signForm(shrub);
            sandra.signForm(robot);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        // exécuter un form non signé
        try {
            sandra.executeForm(pardon);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        // Michel essaie d'exécuter un form signé mais grade insuffisant
        try {
            michel.executeForm(shrub);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        //  Le boss signe et exécute tout
        boss.signForm(pardon);
        boss.executeForm(pardon);
        boss.executeForm(shrub);
        boss.executeForm(robot);

    } catch (std::exception &e) {
        std::cerr << " exception  : " << e.what() << std::endl;
    }

    return 0;
}