#include "include/Contact.hpp"
#include "include/PhoneBook.hpp"
#include <cstdio>
#include <iostream>
#include <string>

// TODO : !!!ignore all backspaces (entree)!!!
int	main(void) {
	bool		exit = false;
	std::string	input;
	PhoneBook	Phonebook;

	while (!exit) {
		std::cout << "Enter a command : ";
		if (!std::getline(std::cin, input) || input == "EXIT") {
			exit = true;
		} else if (input == "ADD" && Phonebook.add()) {
			exit = true;
		} else if (input == "SEARCH" && Phonebook.search()) {
			exit = true;
		}
	}
	return (0);
}
