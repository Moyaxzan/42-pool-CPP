#include "Brain.hpp"
#include <iostream>
#include <string>

//CONSTRUCTORS ----------------------------------------------------//

Brain::Brain(void) {
	std::cout << "Brain base constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = "...nothing...";
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

std::string	Brain::get_idea(int index) const {
	if (index < 0 || index > 99) {
		std::cout << "wrong index to get idea" << std::endl;
		return ("NULL");
	}
	return (this->_ideas[index]);
}

void	Brain::set_idea(int index, std::string idea) {
	if (index < 0 || index > 99) {
		std::cout << "wrong index to set idea" << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}

//MEMBER FUNCTIONS ----------------------------------------------------//
