#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

//CONSTRUCTORS ----------------------------------------------------//

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog base constructor" << std::endl;
	this->_brain = new Brain;
}

Dog::Dog(const Dog &other) : Animal(other._type) {
	std::cout << "Dog assign constructor" << std::endl;
	this->_brain = new Brain(*(other._brain));
}

Dog::~Dog() {
	std::cout << "Dog Destructor." << std::endl;
	delete this->_brain;
}

//OPERATORS ----------------------------------------------------//

Dog	&Dog::operator=(const Dog &other) {
	std::cout << "Dog operator = called" << std::endl;
	if (&other == this) {
		return (*this);
	}
	if (this->_brain) {
		delete this->_brain;
	}
	this->_brain = new Brain(*(other._brain));
	this->_type = other._type;
	return (*this);
}

//GETTERS SETTERS -----------------------------------------------------//

std::string	Dog::get_idea(int index) const {
	return (this->_brain->get_idea(index));
}

void	Dog::set_idea(int index, std::string idea) {
	return (this->_brain->set_idea(index, idea));
}

//MEMBER FUNCTIONS ----------------------------------------------------//

void	Dog::makeSound(void) const {
	std::cout << "woof woof..." << std::endl;
}
