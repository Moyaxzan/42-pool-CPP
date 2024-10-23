#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <ctime>
#include <cstdlib>

// --------- CANONICAL ORTHODOX FUNCTIONS -----------------------------

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("Robotomy Request", 72, 45),
	_target(target)
{
	srand(static_cast<unsigned int>(clock() % INT_MAX));
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other.getName(), other.getMinSignGrade(), other.getMinExecGrade()),
	_target(other._target)
{
	srand(static_cast<unsigned int>(clock() % INT_MAX));
}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

// --------- GETTERS / SETTERS ---------------------------------------

std::string RobotomyRequestForm::getTarget(void) const { return (this->_target); }


// --------- MEMBER FUNCTIONS ----------------------------------------

void	RobotomyRequestForm::_doExecute(void) const {
	int randomVal = rand();
	std::cout << "RRrrrRRrrRrKKkKkKkkrrkkrkK !!!!" << std::endl;
	if (randomVal & 0b00000001) {
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "Failed to robotomize " << this->_target << std::endl;
	}
}
