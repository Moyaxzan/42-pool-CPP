#include "include/Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

int	request_field(std::string prompt, std::string *field) {
	std::cout << std::endl << "enter " << prompt;
	std::cin >> *field;
	if (field->size() == 0) {
		std::cout << "Invalid input, " << prompt << "cannot be empty" << std::endl;
		return (1);
	}
	return (0);
}

int	Contact::fill_contact(void) {
	if (request_field("first name : ", &(this->name))) {
		return (1);
	}
	if (request_field("last name : ", &(this->last_name))) {
		return (1);
	}
	if (request_field("nickname : ", &(this->nickname))) {
		return (1);
	}
	if (request_field("number : ", &(this->number))) {
		return (1);
	}
	if (request_field("darkest secret : ", &(this->darkest_secret))) {
		return (1);
	}
	return (0);
}
