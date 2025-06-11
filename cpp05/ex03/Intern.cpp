#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	return *this;
}

AForm *makeP(const std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *makeR(const std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *makeS(const std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    long unsigned int i = 0;
    std::string possible_forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    AForm * (*form_makers[])(const std::string target) = {makeP, makeR, makeS};
    while (i < (sizeof(possible_forms) / sizeof(possible_forms[0])))
    {
        if (name == possible_forms[i])
        {
            return form_makers[i](target);
        }

        i++;
    }
    std::cout << "Intern couldnt create " << name << std::endl;
    return 0;
}