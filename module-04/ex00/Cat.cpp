#include "Cat.hpp"
#include "Animal.hpp"

//CONSTRUCTORS ----------------------------------------------------//

Cat::Cat(void) : Animal("Cat") {
}

Cat::Cat(const Cat &other) : Animal(other._type) {
}

Cat::~Cat() {
}

//OPERATORS ----------------------------------------------------//

Cat	&Cat::operator=(const Cat &other) {
	this->_type = other._type;
	return (*this);
}

//MEMBER FUNCTIONS ----------------------------------------------------//
