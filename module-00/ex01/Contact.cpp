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
	while (field->size() == 0) {
		std::cout << "Invalid input, " << prompt << "cannot be empty" << std::endl;
		std::cout << std::endl << "enter " << prompt;
		std::cin >> *field;
	}
	return (0);
}

int	Contact::fill_contact(void) {
	request_field("first name : ", &(this->name)); 
	request_field("last name : ", &(this->last_name)); 
	request_field("nickname : ", &(this->nickname)); 
	request_field("number : ", &(this->number)); 
	request_field("darkest secret : ", &(this->darkest_secret)); 
	return (0);
}
