#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
    AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm constructor called for target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
    std::cout << "ShrubberyCreationForm copy constructor called for target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default_target")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw std::runtime_error("Form is not signed yet!");
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream file((target + "_shrubbery").c_str());

    if (!file)
    {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
        return;
    }

    int line_nb = 20;
    int col_nb = 30;

    for (int l = 1; l <= line_nb; l++)
    {
        for (int c = 1; c <= col_nb; c++)
        {
            if (l * 2 >= col_nb)
            {
                if (c == col_nb / 2)
                    file << "*";
                else
                    file << " ";
            }
            else if (c + l <= col_nb / 2 || c - l >= col_nb / 2)
                file << " ";
            else
                file << "*";
        }
        file << std::endl;
    }

    file.close();
    std::cout << "Shrubbery created in " << target << "_shrubbery" << std::endl;
}
