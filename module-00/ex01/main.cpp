#include "include/Contact.hpp"
#include "include/PhoneBook.hpp"
#include <iostream>
#include <string>

// TODO : !!!ignore all backspaces (entree)!!!
int	main(void) {
	bool		exit = false;
	std::string	input;
	PhoneBook	Phonebook;

	while (!exit) {
		std::cout << "Enter a command : ";
		std::cin >> input;
		if (input == "EXIT") {
			exit = true;
		} else if (input == "ADD") {
			Phonebook.add();
		} else if (input == "SEARCH") {
			Phonebook.search();
		}
	}
	return (0);
}
