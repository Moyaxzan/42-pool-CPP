#include "Brain.hpp"

//CONSTRUCTORS ----------------------------------------------------//

Brain::Brain(void) {
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
