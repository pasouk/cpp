#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
    private:
        unsigned int        _n;
        std::vector<int>    _numbers;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void    addNumber(int toAdd);
        int     shortestSpan();
        int     longuestSpan();

};

#endif