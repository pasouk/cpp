#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) 
{
    std::cout << "\033[32m" << "Default constructor called" << "\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name) : name(name), grade(150) 
{
    std::cout << "\033[32m" << "Chosen name constructor called" << "\033[0m" << std::endl;

}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) 
{
    std::cout << "\033[32m" << "Parameterized constructor called" << "\033[0m" << std::endl;

    if (grade < 1) 
        throw GradeTooHighException();
    else if (grade > 150) 
        throw GradeTooLowException();
    else
		this->grade = grade;
    
}

Bureaucrat::Bureaucrat(int grade) : name("unknown") 
{
    std::cout << "\033[32m" << "Chosen grade constructor called" << "\033[0m" << std::endl;
    if (grade < 1) 
        throw GradeTooHighException();
    else if (grade > 150) 
        throw GradeTooLowException();
    else
		this->grade = grade;
    
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) 
{
    std::cout << "\033[32m" << "Copy constructor called" << "\033[0m" << std::endl;

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() 
{
    std::cout << "\033[31m" << "Destructor called"<< "\033[0m" << std::endl;
}

const std::string Bureaucrat::getName() const 
{
    return this->name;
}

int Bureaucrat::getGrade() const 
{
    return this->grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void Bureaucrat::incrementGrade() 
{
    if (this->grade <= 1) 
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade() 
{
    if (this->grade >= 150) 
        throw GradeTooLowException();
    this->grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) 
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." ;
    return os;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}