#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>

class ScalarConvert
{
private:
    ScalarConvert();
    ScalarConvert(const ScalarConvert &other);
    ScalarConvert &operator=(const ScalarConvert &other);
    ~ScalarConvert();
public:
    

    static void convert(std::string literal);
};


#endif