#include "Animal.hpp"
#include <iostream>

//CONSTRUCTORS ----------------------------------------------------//

Animal::Animal(void) {
	std::cout << "Animal base constructor" << std::endl;
	this->_type = "None";
}

Animal::Animal(std::string type) {
	std::cout << "Animal string base constructor" << std::endl;
	this->_type = type;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal assign constructor called" << std::endl;
	this->_type = other._type;
}

Animal::~Animal() {
	std::cout << "animal destructor" << std::endl;
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
		std::cout << "..." << std::endl;
	}
}
