#include "Span.hpp"

Span::Span() : _n(0)
{}

Span::Span(unsigned int n) : _n(n)
{}

Span::Span(const Span &other) : _n(other._n), _numbers(other._numbers)
{}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _n = other._n;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{}

void Span::addNumber(int toAdd)
{
    if (_numbers.size() < _n)
        _numbers.push_back(toAdd);
    else
        throw std::runtime_error("Span is full !\n");
}

int Span::longuestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to compute a span.");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return std::abs(max - min);
}



int span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to compute a span.");

    std::vector<int> vec_sorted = _numbers;
    vec_sorted.sort();
    int retVal = -1;
    for(i = 0; i < vec_sorted.size(); i++)
    {
        if ()
    }
}