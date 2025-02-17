#include "Harl.hpp"

int main(int argc, char** argv)
{
    
    if (argc != 2)
    {
        std::cout << "please enter exactly one argument ! DEBUG, INFO, WARNING or ERROR" << std::endl;
        return 0;
    }
    else
    {
        Harl harl;
        harl.complain(argv[1]);
        return 1;
    }
}