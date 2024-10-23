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
	Bureaucrat bigboss("boss", 1);

	ShrubberyCreationForm shrub("grandma's_garden");
	bigboss.signForm(shrub);
	bigboss.executeForm(shrub);

	RobotomyRequestForm robotomy("neighbour");
	bigboss.signForm(robotomy);
	for (int i = 0; i < 10; i++) {
		bigboss.executeForm(robotomy);
	}

	PresidentialPardonForm pardon("Another President");
	bigboss.signForm(pardon);
	bigboss.executeForm(pardon);
	return (0);
}
