#include "./include/PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

PhoneBook::PhoneBook(void) {
	this->nb_of_contacts = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

int	PhoneBook::add(void) {
	if (this->nb_of_contacts < 8) {
		if (this->contacts[this->nb_of_contacts].fill_contact()) {
			return (1);
		}
		this->nb_of_contacts++;
	} else {
		int	i = 0;
		while (i < 7) {
			this->contacts[i] = this->contacts[i + 1];
			i++;
		}
		if (this->contacts[7].fill_contact()) {
			return (1);
		}
	}
	return (0);
}

std::string	get_string(std::string str) {
	std::string	res;

	if (str.length() > 10) {
		res = str.substr(0, 9) + ".";
	} else {
		res = std::string(10 - str.length(), ' ') + str;
	}
	return (res);
}

int	PhoneBook::search(void) {
	int			i = 0;
	std::string	index;

	if (!this->nb_of_contacts) {
		std::cout << "\tEMPTY TABLE\t" << std::endl << "    (register contacts)" << std::endl;
		return (0);
	}
	std::cout << "____________________________________________" << std::endl;
	std::cout << "|  index  |first name| last name| nickname |" << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	while (i < this->nb_of_contacts) {
		std::cout << "|        " << i << "|";
		std::cout << get_string(this->contacts[i].get_name()) << "|";
		std::cout << get_string(this->contacts[i].get_last_name()) << "|";
		std::cout << get_string(this->contacts[i].get_nickname()) << "|" << std::endl;
		i++;
	}
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	do {
		std::cout << "enter a contact index : ";
		if (!std::getline(std::cin, index)) {
			return (1);
		}
	} while (index.find_first_not_of("0123456789") != std::string::npos \
				|| this->nb_of_contacts <= std::atoi(index.c_str()) \
				|| index.length() < 1);
	this->contacts[std::atoi(index.c_str())].print_contact();
	return (0);
}
