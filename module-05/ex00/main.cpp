#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void) {
	{
		Bureaucrat bigboss("Bernard", 1);
		try {
			bigboss.incrementGrade();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << bigboss << std::endl;
		try {
			bigboss.decrementGrade();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << bigboss << std::endl;
	}
	{
		Bureaucrat larbin("stagiaire", 150);
		try {
			larbin.decrementGrade();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << larbin << std::endl;

		try {
			larbin.incrementGrade();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << larbin << std::endl;
	}
	return (0);
}
