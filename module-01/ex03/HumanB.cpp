#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	this->_weapon = NULL;
}

HumanB::~HumanB() {
}

void	HumanB::attack() {
	if (this->_weapon == NULL) {
		std::cout << this->_name << " cannot attack without a weapon" << std::endl;
	} else {
		std::cout << this->_name << " attacks with their ";
		std::cout << this->_weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
