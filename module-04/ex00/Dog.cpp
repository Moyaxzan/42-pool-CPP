#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

//CONSTRUCTORS ----------------------------------------------------//

Dog::Dog(void) : Animal("Dog") {
}

Dog::Dog(const Dog &other) : Animal(other._type) {
}

Dog::~Dog() {
}

//OPERATORS ----------------------------------------------------//

Dog	&Dog::operator=(const Dog &other) {
	this->_type = other._type;
	return (*this);
}

//MEMBER FUNCTIONS ----------------------------------------------------//
