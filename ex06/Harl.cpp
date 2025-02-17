#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	void (Harl::*fonctions_ptrs[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int currentLevel = -1;

	for(int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			currentLevel = i;
		}
	}

    if (currentLevel == -1)
    {
        std::cout << "Level not recognized: " << level << std::endl;
        return;
    }

    switch (currentLevel)
    {
        case 0:
            (this->*fonctions_ptrs[0])();
			__attribute__ ((fallthrough));
		case 1:
            (this->*fonctions_ptrs[1])();
			__attribute__ ((fallthrough));
        case 2:
            (this->*fonctions_ptrs[2])();
			__attribute__ ((fallthrough));
        case 3:
            (this->*fonctions_ptrs[3])();
            break;
    }

}