#include "include/Contact.hpp"
#include "include/PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void) {
	bool		exit = false;
	std::string	input;

	while (!exit) {
		std::cout << "Enter a command : ";
		std::cin >> input;
		if (input == "EXIT") {
			exit = true;
		} else if (input == "ADD") {
			
		} else if (input == "SEARCH") {

		}
	}
	return (0);
}
