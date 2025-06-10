#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private: 
        const std::string   name;
        bool                isSigned;
        const int           gradeToSign;
        const int           gradeToExecute;

    public:
        Form();
        Form(const std::string name, int gradeToSign, int gradeToExecute);
        Form(Form &other);
        ~Form();

        Form &operator=(const Form &other);

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char*what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char*what() const throw();
        };

        const std::string   getName() const;
        bool                getIsSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;

        void beSigned(const Bureaucrat &signer);
};


std::ostream &operator<<(std::ostream &os, const Form &form);

#endif