#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <iostream>

// --------- CANONICAL ORTHODOX FUNCTIONS -----------------------------

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("Presidential Pardon", 25, 5),
	_target(target)
{}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm(other.getName(), other.getMinSignGrade(), other.getMinExecGrade()),
	_target(other._target)
{}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

// --------- GETTERS / SETTERS ---------------------------------------

std::string PresidentialPardonForm::getTarget(void) const { return (this->_target); }


// --------- MEMBER FUNCTIONS ----------------------------------------

void	PresidentialPardonForm::_doExecute(void) const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
