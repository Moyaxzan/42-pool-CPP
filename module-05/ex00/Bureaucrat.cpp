#include "Bureaucrat.hpp"
#include <string>

Bureaucrat::Bureaucrat(void) : _name("stagiaire"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooLowException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}


int Bureaucrat::getGrade(void) const { return (this->_grade); }

const std::string& Bureaucrat::getName(void) const { return (this->_name); }

void Bureaucrat::incrementGrade(void) {
	if (this->_grade <= 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		this->_grade--;
	}
}

void Bureaucrat::decrementGrade(void) {
	if (this->_grade >= 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		this->_grade++;
	}
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const & burocrat) {
	os << burocrat.getName() << "'s grade: " << burocrat.getGrade();
	return (os);
}
