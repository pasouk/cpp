#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
    AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm constructor called for target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target)
{
    std::cout << "PresidentialPardonForm copy constructor called for target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target("default_target")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
   if (!this->getIsSigned())
    {
        std::cout << "Form is not signed yet!" << std::endl;
        return;
    }
    if (executor.getGrade() > this->getGradeToExecute())
    {
        throw GradeTooLowException();
    }
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;

}