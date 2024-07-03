#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() {
}

Harl::~Harl() {
}

void	Harl::complain(std::string level) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*complaints[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int			i;
	for (i = 0; i < 4; i++) {
		if (!level.compare(levels[i])) {
			break ;
		}
	}
	switch (i) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*complaints[0])();
			// fall through
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			(this->*complaints[1])();
			// fall through
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			(this->*complaints[2])();
			// fall through
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*complaints[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << " I really do!" << std::endl << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn’t put enough bacon in my burger!";
	std::cout << " If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I’ve been coming for years whereas you ";
	std::cout << " started working here since last month." << std::endl << std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl << std::endl;
}
