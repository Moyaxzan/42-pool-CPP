#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("stagiaire"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
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

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn't sign ";
		std::cout << form.getName() << " because ";
		std::cout << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name << " signed ";
	std::cout << form.getName() << std::endl;
	return ;
}

void Bureaucrat::executeForm(AForm &form) const {
	if (!form.getIsSigned()) {
		return ;
	}
	try {
		form.execute(*this);
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn't execute ";
		std::cout << form.getName() << " because ";
		std::cout << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name << " executed ";
	std::cout << form.getName() << std::endl;
	return ;
}
