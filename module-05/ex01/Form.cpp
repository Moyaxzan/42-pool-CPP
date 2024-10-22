#include "Form.hpp"
#include "Bureaucrat.hpp"

// --------- CANONICAL ORTHODOX FUNCTIONS -----------------------------

Form::Form(void) : _name("Form"), _isSigned(false), _minSignGrade(150), _minExecGrade(150) {}

Form::Form(const std::string name, int minSignGrade, int minExecGrade) :
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

Form::Form(const Form& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_minSignGrade(other._minSignGrade),
	_minExecGrade(other._minExecGrade)
{}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->_minExecGrade = other._minExecGrade;
		this->_minSignGrade = other._minSignGrade;
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form(void) {}

// --------- GETTERS / SETTERS ---------------------------------------

std::string const & Form::getName(void) const { return (this->_name); }

bool Form::getIsSigned(void) const { return (this->_isSigned); }

int Form::getMinSignGrade(void) const { return (this->_minSignGrade); }

int Form::getMinExecGrade(void) const { return (this->_minExecGrade); }

// --------- MEMBER FUNCTIONS ----------------------------------------

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (this->_isSigned == true) {
		throw Form::FormAlreadySigned();
	} else if (bureaucrat.getGrade() > this->_minSignGrade) {
		throw Form::GradeTooLowException();
	} else {
		this->_isSigned = true;
	}
}

// --------- OTHERS --------------------------------------------------

std::ostream& operator<<(std::ostream& os, Form const & form) {
	os << "Form: " << form.getName() << ":\n";
	os << "signed = " << form.getIsSigned() << ",\n";
	os << "minSignGrade = " << form.getMinSignGrade() << ",\n";
	os << "minExecGrade = " << form.getMinExecGrade() << ",\n";
	return (os);
}
