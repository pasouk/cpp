#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:

    public:

		Intern();
		Intern(const Intern &src);
		~Intern();

		Intern &operator=(const Intern &other);

        AForm *makeForm(std::string name, std::string target);
};


#endif