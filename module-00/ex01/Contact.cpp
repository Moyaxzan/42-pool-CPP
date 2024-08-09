#include "include/Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

std::string	Contact::get_name(void) {
	return (this->name);
}

std::string	Contact::get_last_name(void) {
	return (this->last_name);
}

std::string	Contact::get_nickname(void) {
	return (this->nickname);
}

void	Contact::print_contact(void) {
	std::cout << "name : " << this->name << std::endl;
	std::cout << "last name : " << this->last_name << std::endl;
	std::cout << "nickname : " << this->nickname << std::endl;
	std::cout << "number : " << this->number << std::endl;
	std::cout << "darkest secret : " << this->darkest_secret << std::endl;
	std::cout << std::endl;
	return ;
}

int	request_field(std::string prompt, std::string *field) {
	do {
		std::cout << std::endl << "enter " << prompt;
		if (!std::getline(std::cin, *field)) {
			return (1);
		}
	} while (field->length() < 1);
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
