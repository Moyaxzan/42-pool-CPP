#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <iostream>

// --------- CANONICAL ORTHODOX FUNCTIONS -----------------------------

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("Shrubbery Creation", 145, 137),
	_target(target)
{}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other.getName(), other.getMinSignGrade(), other.getMinExecGrade()),
	_target(other._target)
{}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// --------- GETTERS / SETTERS ---------------------------------------

std::string ShrubberyCreationForm::getTarget(void) const { return (this->_target); }


// --------- MEMBER FUNCTIONS ----------------------------------------

void	ShrubberyCreationForm::_doExecute(void) const {
	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cerr << "Error while opening file " << this->_target << "_shrubbery" << std::endl;
	}
	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      /\\\\/ \\\n";
	file.close();
}
