#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

// Form* createForm(const char * name, int minSignGrade, int minExecGrade) {
// }

// Bureaucrat* createBureaucrat(const char* name, int grade) {
// }

int main(void) {
	Bureaucrat bigboss("boss", 1);
	ShrubberyCreationForm shrub("garden");

	bigboss.signForm(shrub);
	bigboss.executeForm(shrub);
	return (0);
}
