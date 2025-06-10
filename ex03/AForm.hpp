#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private: 
        const std::string   name;
        bool                isSigned;
        const int           gradeToSign;
        const int           gradeToExecute;

    public:
        AForm();
        AForm(const std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        virtual ~AForm();

        AForm &operator=(const AForm &other);

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
        virtual void execute(const Bureaucrat &executor) const = 0;
};


std::ostream &operator<<(std::ostream &os, const AForm &Aform);

#endif