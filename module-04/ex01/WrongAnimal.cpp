#include "WrongAnimal.hpp"
#include <iostream>

//CONSTRUCTORS ----------------------------------------------------//

WrongAnimal::WrongAnimal(void) {
	this->_type = "WrongNone";
}

WrongAnimal::WrongAnimal(std::string type) {
	this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	this->_type = other._type;
}

WrongAnimal::~WrongAnimal() {
}

//OPERATORS ----------------------------------------------------//

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	this->_type = other._type;
	return (*this);
}

//GET/SETTERS ----------------------------------------------------//

std::string	WrongAnimal::getType(void) const {
	return (this->_type);
}

//MEMBER FUNCTIONS ----------------------------------------------------//

void	WrongAnimal::makeSound(void) const {
	if (this->_type == "WrongCat") {
		std::cout << "PWET PWET *says the WrongCat*" << std::endl;
	} else {
		std::cout << "SDLKFJLSKDJFLSDKFJ *says the horrific creature*" << std::endl;
	}
}
