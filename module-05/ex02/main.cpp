#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

// Form* createForm(const char * name, int minSignGrade, int minExecGrade) {
// }

// Bureaucrat* createBureaucrat(const char* name, int grade) {
// }

int main(void) {
	Bureaucrat bigboss("Boss", 1);
	Bureaucrat intern("Intern", 150);

	std::cout << std::endl << "---------- SHRUBBERY CREATION FORM -----------------" << std::endl;
	ShrubberyCreationForm shrub("grandma's_garden");
	bigboss.signForm(shrub);
	bigboss.executeForm(shrub);

	std::cout << std::endl << "---------- ROBOTOMY REQUEST FORM -------------------" << std::endl;
	RobotomyRequestForm robotomy("neighbour");
	bigboss.signForm(robotomy);
	for (int i = 0; i < 10; i++) {
		bigboss.executeForm(robotomy);
	}

	std::cout << std::endl << "---------- PRESIDENTIAL PARDON FORM ----------------" << std::endl;
	PresidentialPardonForm pardon("Another President");
	bigboss.signForm(pardon);
	bigboss.executeForm(pardon);

	std::cout << std::endl << "---------- BAD INPUTS ------------------------------" << std::endl;
	try {
		intern.executeForm(pardon);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl << std::endl;
	}

	RobotomyRequestForm roboto("unsigned robotomy");
	try {
		bigboss.executeForm(roboto);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
