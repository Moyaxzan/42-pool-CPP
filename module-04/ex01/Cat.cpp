#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

//CONSTRUCTORS ----------------------------------------------------//

Cat::Cat(void) : Animal("Cat") {
	std::cout << "cat base constructor" << std::endl;
	this->_brain = new Brain;
}

Cat::Cat(const Cat &other) : Animal(other._type) {
	std::cout << "cat assign constructor" << std::endl;
	this->_brain = new Brain(*(other._brain));
}

Cat::~Cat() {
	std::cout << "destructor" << std::endl;
	delete this->_brain;
}

//OPERATORS ----------------------------------------------------//

Cat	&Cat::operator=(const Cat &other) {
	std::cout << "cat operator = called" << std::endl;
	if (&other == this) {
		return (*this);
	}
	delete this->_brain;
	this->_brain = new Brain(*(other._brain));
	this->_type = other._type;
	return (*this);
}

//MEMBER FUNCTIONS ----------------------------------------------------//
