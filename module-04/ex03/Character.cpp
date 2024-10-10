#include "Character.hpp"

Character::Character(std::string const name) {
	this->_name = name;
	for(int i = 0; i < 4; i++) {
		this->_invetory[i] = NULL;
	}
}
