#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <string>


class Bureaucrat 
{
    private:
        const std::string   name;
        int                 grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(int grade);
        Bureaucrat(const std::string name);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;

        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            public:
                virtual const char *what() const throw();
        };


        void incrementGrade();
        void decrementGrade();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif