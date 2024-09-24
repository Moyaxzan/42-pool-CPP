#include "Animal.hpp"
#include <iostream>

//CONSTRUCTORS ----------------------------------------------------//

Animal::Animal(void) {
	this->_type = "None";
}

Animal::Animal(std::string type) {
	this->_type = type;
}

Animal::Animal(const Animal &other) {
	this->_type = other._type;
}

Animal::~Animal() {
}

//OPERATORS ----------------------------------------------------//

Animal &Animal::operator=(const Animal &other) {
	this->_type = other._type;
	return (*this);
}

//GET/SETTERS ----------------------------------------------------//

std::string	Animal::getType(void) const {
	return (this->_type);
}

//MEMBER FUNCTIONS ----------------------------------------------------//

void	Animal::makeSound(void) const {
	if (this->_type == "Dog") {
		std::cout << "wouf wouf *says the dog*" << std::endl;
	} else if (this->_type == "Cat") {
		std::cout << "meeeeeewwwww *says the cat*" << std::endl;
	} else {
		std::cout << "asdfhaskjdghlaksjdhflasd *says the creature*" << std::endl;
	}
}
