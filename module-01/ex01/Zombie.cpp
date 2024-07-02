#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(void) {
}

Zombie::~Zombie() {
	std::cout << this->_name << " has been killed" << std::endl;
}

void	Zombie::set_name(std::string name) {
	this->_name = name;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
