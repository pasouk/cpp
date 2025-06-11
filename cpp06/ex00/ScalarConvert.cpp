#include "ScalarConvert.hpp"
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cerrno>

/*
ScalarConvert::ScalarConvert()
{
    
}

ScalarConvert::ScalarConvert(const ScalarConvert &other)
{
    
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert &other)ScalarConvert()
{
    
}

ScalarConvert::~ScalarConvert()
{
    
}*/



bool isFloat(std::string str)
{
    int dot_number = 0;
    std::string::size_type tmp_pos;

    tmp_pos = str.find('f');
    if (tmp_pos == std::string::npos || tmp_pos != str.length() - 1)
        return false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-' && str[i] != 'f')
            return false;
        if (str[i] == '.')
            dot_number ++;
        if (str[i] == '-' && (i != 0 || str.length() == 1)) 
            return false;
    }
    if (dot_number != 1)
        return false;

    errno = 0;
    char* endPtr;
    std::strtof(str.c_str(), &endPtr);
    if (*endPtr != 'f' || *(endPtr + 1) != '\0')
        return false;
    if (errno == ERANGE)
        return false;
    return true;
}

bool isInt(std::string str)
{
    long int nb;
    for (size_t i = 0; i < str.length() ; i++)
    {
        if (!isdigit(str[i]) && str[i] != '-')
            return false;
        if (str[i] == '-' && (i != 0 || str.length() == 1))
            return false;
    }
    nb = atol(str.c_str());
    if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
        return false;
    return true;
}

bool isChar (std::string str)
{
    if (str.length() == 1 && !isdigit(str[0]))
        return true;
    return false;
}

bool isDouble(std::string str)
{
    int dot_number = 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-')
            return false;
        if (str[i] == '.')
            dot_number++;
        if (str[i] == '-' && i != 0)
            return false;
    }
    if (dot_number != 1)
        return false;

    errno = 0;
    char* endPtr;
    std::strtod(str.c_str(), &endPtr);
    if (*endPtr != '\0')
        return false;
    if (errno == ERANGE)
        return false;
    return true;
}

void convertFromChar(std::string literal)
{
    char    c = literal[0];
    int     nb_int = static_cast<int>(c);
    float   nb_float = static_cast<float>(c);
    double  nb_double = static_cast<double>(c);

    std::cout << "char: ";
    if (isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "int: " << nb_int << std::endl;
    std::cout << "float: " << nb_float << "f" << std::endl;
    std::cout << "double: " << nb_double << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

void convertFromInt(std::string literal)
{
    int     nb_int;
    float   nb_float;
    double  nb_double; 

    nb_int = atoi(literal.c_str());
    nb_float = static_cast<float>(nb_int);
    nb_double = static_cast<double>(nb_int);

    if (nb_int < 0 || nb_int > 127)
        std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(nb_int)))
        std::cout << "char: '" << static_cast<char>(nb_int) << "'" << std::endl;
    else
        std::cout << "char: Non displayable " << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "int: " << nb_int << std::endl;
    std::cout << "float: " << nb_float << "f" << std::endl;
    std::cout << "double: " << nb_double << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

void convertFromFloat(std::string literal)
{
    float   nb_float;
    double  nb_double; 

    nb_float = atof(literal.c_str());
    nb_double = static_cast<double>(nb_float);

    if (nb_float < 0 || nb_float > 127)
        std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(nb_float)))
        std::cout << "char: '" << static_cast<char>(nb_float) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (nb_float < std::numeric_limits<int>::min() || nb_float > std::numeric_limits<int>::max())
        std::cout << "Int : non displayable" << std::endl;
    else 
        std::cout << "Int : " << static_cast<int>(nb_float) << std::endl;
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << nb_float << "f" << std::endl;
    std::cout << "double: " << nb_double << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

void convertFromDouble(std::string literal)
{
    float   nb_float;
    double  nb_double; 

    nb_double = atof(literal.c_str());
    nb_float = static_cast<float>(nb_double);

    if (nb_float < 0 || nb_float > 127)
        std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<char>(nb_float)))
        std::cout << "char: '" << static_cast<char>(nb_float) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (nb_float < std::numeric_limits<int>::min() || nb_float > std::numeric_limits<int>::max())
        std::cout << "Int : non displayable" << std::endl;
    else 
        std::cout << "Int : " << static_cast<int>(nb_float) << std::endl;
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << nb_float << "f" << std::endl;
    std::cout << "double: " << nb_double << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

void convertFromPseudoDoubles(std::string literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << literal << "f" << std::endl;
    std::cout << "double: " << literal << std::endl;
}

void convertFromPseudoFloats(std::string literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << literal << std::endl;
    std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
}

bool isPseudoFloats(std::string literal)
{
    const std::string pseudoFloats[] = {"-inff", "+inff", "nanf"};

    for (long unsigned int i = 0; i < sizeof(pseudoFloats) / sizeof(pseudoFloats[0]); i++)
        if (literal == pseudoFloats[i])
            return true;
    return false;
}

bool isPseudoDoubles(std::string literal)
{
    const std::string pseudoDoubles[] = {"-inf", "+inf", "nan"};

    for (long unsigned int i = 0; i < sizeof(pseudoDoubles) / sizeof(pseudoDoubles[0]); i++)
        if (literal == pseudoDoubles[i])
            return true;
    return false;
}

void ScalarConvert::convert(std::string literal)
{

    if (literal.empty())
    {
        std::cout << "error : empty imput \n";
        return;
    }
    if(isPseudoFloats(literal))
        convertFromPseudoFloats(literal);
    else if(isPseudoDoubles(literal))
        convertFromPseudoDoubles(literal);
    else if(isChar(literal))
        convertFromChar(literal);
    else if(isInt(literal))
        convertFromInt(literal);
    else if (isDouble(literal))
        convertFromDouble(literal);
    else if (isFloat(literal))
        convertFromFloat(literal);
    else
        std::cout << "Error: literal not recognized" << std::endl;

}