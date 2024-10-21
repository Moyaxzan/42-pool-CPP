#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include <iostream>

Character::Character(std::string const name) {
	this->_name = name;
	for(int i = 0; i < 4; i++) {
		this->_invetory[i] = NULL;
	}
}

Character::Character(const Character& other) {
	this->_name = other._name;
	for (int i= 0; i < 4; i++) {
		if (other._invetory[i]) {
			this->_invetory[i] = other._invetory[i]->clone();
		} else {
			this->_invetory[i] = NULL;
		}
	}
}

Character&	Character::operator=(const Character& other) {
	this->_name = other._name;
	this->deleteInventory();
	for (int i = 0; i < 4; i++) {
		if (other._invetory[i]) {
			this->_invetory[i] = other._invetory[i]->clone();
		} else {
			this->_invetory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character(void) {
	std::cout << "deleting :" << this->_name << std::endl;
	this->deleteInventory();
}

std::string const &	Character::getName(void) const {
	return (this->_name);
}

void	Character::deleteInventory(void) {
	for (int i = 0; i < 4; i++) {
		std::cout << "Deleting inventory at index " << i << std::endl;
		if (this->_invetory[i]) {
			delete this->_invetory[i];
			this->_invetory[i] = NULL;
		}
	}
}

void	Character::equip(AMateria *m) {
	int	i = 0;

	while (this->_invetory[i] && i < 4) {
		i++;
	}
	if (i < 4) {
		this->_invetory[i] = m;
	} else {
		std::cout << "equip: inventory already full" << std::endl;
	}
}

void	Character::unequip(int index) {
	if (index < 0 || index > 3) {
		std::cout << "unequip: invalid index." << std::endl;
		return ;
	}
	this->_invetory[index] = NULL;
}

void	Character::use(int index, ICharacter& target) {
	if (index < 0 || index > 3) {
		std::cout << "use: invalid index." << std::endl;
		return ;
	}
	if (!this->_invetory[index]) {
		return ;
	}
	if (this->_invetory[index]->getType() == "ice") {
		std::cout << "* shoots an Ice bolt at " << target.getName() << " *"<< std::endl;
	} else if (this->_invetory[index]->getType() == "cure") {
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	} else {
		std::cout << "* unknown type of materia... *" << std::endl;
	}
}

AMateria*	Character::getMateria(int index) {
	if (index > 3 || index < 0) {
		std::cout << "getMateria: invalid index." << std::endl;
		return (NULL);
	}
	return (this->_invetory[index]);
}


