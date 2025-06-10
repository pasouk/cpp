#include "AForm.hpp"

AForm::AForm() : name("unknownAForm"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    std::cout << "\033[32m" << "AForm default constructor called" << "\033[0m" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooHighException();

    std::cout << "\033[32m" << "AForm parametrized constructor called" << "\033[0m" << std::endl;

}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "\033[32m" << "AForm copy constructor called" << "\033[0m" << std::endl;

}

AForm::~AForm()
{
    std::cout << "\033[31m" << "AForm destructor called" << "\033[0m" << std::endl;

}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    
    std::cout << "\033[32m" << "AForm copy assignment called" << "\033[0m" << std::endl;
    return *this;
}

const std::string AForm::getName() const 
{
     return name; 
}

bool AForm::getIsSigned() const 
{
     return isSigned; 
}

 int AForm::getGradeToSign() const 
{
     return gradeToSign; 
}

 int AForm::getGradeToExecute() const 
{
     return gradeToExecute; 
}

void AForm::beSigned(const Bureaucrat &signer)
{
    if (this->isSigned)
    {
        std::cout << this->name << " AForm is already signed" << std::endl;
        return;
    }
    if (signer.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    
    this->isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: grade too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
    os << "AForm " << AForm.getName()
       << " [Signed: " << (AForm.getIsSigned() )
       << ", Grade to sign: " << AForm.getGradeToSign()
       << ", Grade to execute: " << AForm.getGradeToExecute() << "]";
    return os;
}