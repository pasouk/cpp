#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime> 

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
    AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm constructor called for target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
{
    std::cout << "RobotomyRequestForm copy constructor called for target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default_target")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw std::runtime_error("Form is not signed yet!");
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "BRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;

    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << "Opération réussie !" << std::endl;
    else
        std::cout << "Opération échouée." << std::endl;
}