#include "./include/PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook(void) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

int	PhoneBook::add(void) {
	if (this->nb_of_contacts < 8) {
		this->contacts[nb_of_contacts].fill_contact();
		this->nb_of_contacts++;
	} else {
		int	i = 0;
		while (i < 7) {
			this->contacts[i] = this->contacts[i + 1];
			i++;
		}
		this->contacts[7].fill_contact();
	}
	return (0);
}

std::string	get_string(std::string str) {
	std::string	res;

	if (str.length() > 9) {
		res = str.substr(0, 9) + ".";
	} else {
		res = str;
	}
	int	len = res.length();
	int padding = (10 - len) / 2;
	res = std::string(padding, ' ') + res + std::string(padding, ' ');
	if ((10 - len) % 2) {
        res += " ";
    }
	return (res);
}

int	PhoneBook::search(void) {
	int			i = 0;
	int			index;

	//TODO : protect when table empty ?
	//print search table
	std::cout << "____________________________________________" << std::endl;
	std::cout << "|  index  |first name| last name| nickname |" << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	while (i < this->nb_of_contacts) {
		std::cout << "|    " << i << "    |";
		std::cout << get_string(this->contacts[i].get_name()) << "|";
		std::cout << get_string(this->contacts[i].get_last_name()) << "|";
		std::cout << get_string(this->contacts[i].get_nickname()) << "|" << std::endl;
		i++;
	}

	//TODO : protect ->
	std::cout << "enter a contact index : ";
	std::cin >> index;

	this->contacts[index].print_contact();
	return (0);
}
