#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <vector>

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
        void    addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     shortestSpan();
        int     longuestSpan();

};

#endif