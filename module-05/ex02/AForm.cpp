#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// --------- CANONICAL ORTHODOX FUNCTIONS -----------------------------

AForm::AForm(void) : _name("Form"), _isSigned(false), _minSignGrade(150), _minExecGrade(150) {}

AForm::AForm(const std::string name, int minSignGrade, int minExecGrade) :
	_name(name),
	_isSigned(false)
{
	if (minSignGrade < 1 || minExecGrade < 1) {
		throw GradeTooHighException();
	} else if (minSignGrade > 150 || minExecGrade > 150) {
		throw GradeTooLowException();
	} else {
		this->_minSignGrade = minSignGrade;
		this->_minExecGrade = minExecGrade;
	}
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_minSignGrade(other._minSignGrade),
	_minExecGrade(other._minExecGrade)
{}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->_minExecGrade = other._minExecGrade;
		this->_minSignGrade = other._minSignGrade;
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm(void) {}

// --------- GETTERS / SETTERS ---------------------------------------

std::string const & AForm::getName(void) const { return (this->_name); }

bool AForm::getIsSigned(void) const { return (this->_isSigned); }

int AForm::getMinSignGrade(void) const { return (this->_minSignGrade); }

int AForm::getMinExecGrade(void) const { return (this->_minExecGrade); }

// --------- MEMBER FUNCTIONS ----------------------------------------

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (this->_isSigned == true) {
		throw AForm::FormAlreadySigned();
	} else if (bureaucrat.getGrade() > this->_minSignGrade) {
		throw AForm::GradeTooLowException();
	} else {
		this->_isSigned = true;
	}
}

void	AForm::execute(const Bureaucrat& executor) const {
	if (!this->_isSigned) {
		throw(AForm::FormNotSigned());
	} else if (executor.getGrade() > this->_minExecGrade) {
		throw (AForm::GradeTooLowException());
	} else {
		this->_doExecute();
	}
}

// --------- OTHERS --------------------------------------------------

std::ostream& operator<<(std::ostream& os, AForm const & form) {
	os << "Form: " << form.getName() << ":\n";
	os << "signed = " << form.getIsSigned() << ",\n";
	os << "minSignGrade = " << form.getMinSignGrade() << ",\n";
	os << "minExecGrade = " << form.getMinExecGrade() << ",\n";
	return (os);
}
