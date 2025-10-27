#ifndef MUTANTSTACK
#define MUTANTSTACK

#include <iostream>
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        typedef std::stack<T> stack;
        typedef typename stack::container_type container;
        typedef typename container::iterator iterator;

        MutantStack() : stack()
        {
            std::cout << "Default Constructor called" << std::endl;
        }

        MutantStack(const stack &src) : stack(src)
        {
            std::cout << "Copy Constructor called" << std::endl;
        }

        ~MutantStack()
        {
            std::cout << "Deconstuctor called" << std::endl;
        }

        MutantStack &operator=(const MutantStack &src)
        {
            if (this != &src)
                stack::operator=(src);
            return *this;
        }

        iterator begin()
        {
            return (stack::c.begin());
        }

        iterator end()
        {
            return (stack::c.end());
        }
};
#endif