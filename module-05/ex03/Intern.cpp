#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void) {}

Intern::Intern(const Intern& other) {
	(void) other;
}

Intern& Intern::operator=(const Intern& other) {
	(void) other;
	return (*this);
}

Intern::~Intern(void) {}

AForm* makeShrubbery(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm* makeRobotomy(const std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm* makePresPardon(const std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string name, const std::string target) {
	std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*makeFunctions[4])(const std::string) = {&makeShrubbery, &makeRobotomy, &makePresPardon};
	for (int i = 0; i < 4; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (makeFunctions[i](target));
		}
	}
	throw(Intern::UnknownForm());
	return (NULL);
}
