#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

//CONSTRUCTORS ----------------------------------------------------//

Cat::Cat(void) : Animal("Cat") {
	this->_brain = new Brain;
}

Cat::Cat(const Cat &other) : Animal(other._type) {
}

Cat::~Cat() {
	delete this->_brain;
}

//OPERATORS ----------------------------------------------------//

Cat	&Cat::operator=(const Cat &other) {
	this->_type = other._type;
	return (*this);
}

//MEMBER FUNCTIONS ----------------------------------------------------//
