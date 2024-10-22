#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

Form* createForm(const char * name, int minSignGrade, int minExecGrade) {
	Form* form;
	try {
		form = new Form(name, minSignGrade, minExecGrade);
	} catch (std::exception &e) {
		std::cout << name << " " << e.what() << std::endl;
		form = NULL;
	}
	return (form);
}

Bureaucrat* createBureaucrat(const char* name, int grade) {
	Bureaucrat* bureaucrat;
	try {
		bureaucrat = new Bureaucrat(name, grade);
	} catch (std::exception &e) {
		std::cout << name << " " << e.what() << std::endl;
		bureaucrat = NULL;
	}
	return bureaucrat;
}

int main(void) {
	//grade too high
	Bureaucrat* fail1 = createBureaucrat("fail1", -1);
	if (fail1) {
		delete fail1;
	}

	// grade too low
	Bureaucrat* fail2 = createBureaucrat("fail2", 151);
	if (fail2) {
		delete fail2;
	}

	//grade too high
	Form*	formfail1 = createForm("formfail1", 0, 2);
	if (formfail1) {
		delete formfail1;
	}

	//grade too low
	Form*	formfail2 = createForm("formfail2", 1000, 2);
	if (formfail2) {
		delete formfail2;
	}

	//grade too high
	Form*	formfail3 = createForm("formfail3", 100, -1);
	if (formfail3) {
		delete formfail3;
	}

	//grade too low
	Form*	formfail4 = createForm("formfail4", 100, 160);
	if (formfail4) {
		delete formfail4;
	}
	
	Bureaucrat* capitalistman = createBureaucrat("Bernard Arnault", 1);
	if (!capitalistman) {
		return (1);
	}
	Bureaucrat* stagiaire = createBureaucrat("Stagiaire", 140);
	if (!stagiaire) {
		delete capitalistman;
		return (1);
	}
	Form* form = createForm("formulary", 100, 2);
	if (!form) {
		delete capitalistman;
		delete stagiaire;
		return (1);
	}

	//grade too low
	stagiaire->signForm(*form);

	//able to sign
	std::cout << std::endl << *form << std::endl;
	capitalistman->signForm(*form);
	std::cout << *form << std::endl;

	delete stagiaire;
	delete capitalistman;
	delete form;
	return (0);
}
