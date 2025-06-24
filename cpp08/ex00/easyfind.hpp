#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &stack, int nb)
{
    return (std::find(stack.begin(), stack.end(), nb));
}



#endif