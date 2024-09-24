#include "Brain.hpp"
#include <iostream>

//CONSTRUCTORS ----------------------------------------------------//

Brain::Brain(void) {
	std::cout << "Brain base constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = "void";
	}
}

Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
}

Brain::~Brain() {
	std::cout << "brain destructor" << std::endl;
}

//OPERATORS ----------------------------------------------------//

Brain &Brain::operator=(const Brain &other) {
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

//GET/SETTERS ----------------------------------------------------//

//MEMBER FUNCTIONS ----------------------------------------------------//
