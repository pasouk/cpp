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

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to compute a span.");

    std::vector<int> vec_sorted = _numbers;
    std::sort(vec_sorted.begin(), vec_sorted.end());
    int retVal = INT_MAX;
    for(size_t i = 1; i < vec_sorted.size(); i++)
    {
        if (vec_sorted[i] - vec_sorted[i - 1] < retVal)
            retVal = vec_sorted[i] - vec_sorted[i - 1];
    }
    return retVal;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + _numbers.size() > _n)
        throw std::runtime_error("Span is full !");
    _numbers.insert(_numbers.end(), begin, end);
}