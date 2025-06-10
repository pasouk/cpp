#include "Form.hpp"

Form::Form() : name("unknownForm"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    std::cout << "\033[32m" << "form default constructor called" << "\033[0m" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();

    std::cout << "\033[32m" << "form parametrized constructor called" << "\033[0m" << std::endl;

}

Form::Form(Form &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "\033[32m" << "form copy constructor called" << "\033[0m" << std::endl;

}

Form::~Form()
{
    std::cout << "\033[31m" << "form destructor called" << "\033[0m" << std::endl;

}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    
    std::cout << "\033[32m" << "form copy assignment called" << "\033[0m" << std::endl;
    return *this;
}

const std::string Form::getName() const 
{
     return name; 
}

bool Form::getIsSigned() const 
{
     return isSigned; 
}

 int Form::getGradeToSign() const 
{
     return gradeToSign; 
}

 int Form::getGradeToExecute() const 
{
     return gradeToExecute; 
}

void Form::beSigned(const Bureaucrat &signer)
{
    if (this->isSigned)
    {
        std::cout << this->name << " Form is already signed" << std::endl;
        return;
    }
    if (signer.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    
    this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form " << form.getName()
       << " [Signed: " << (form.getIsSigned() )
       << ", Grade to sign: " << form.getGradeToSign()
       << ", Grade to execute: " << form.getGradeToExecute() << "]";
    return os;
}