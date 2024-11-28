#include "BitcoinExchange.hpp"
#include <string>


BitcoinExchange::BitcoinExchange(void) {
	this->data_file_.open("data.csv", std::ios::in);
	if (!this->data_file_.is_open()) {
		throw (CouldNotOpenFileException());
	}
}

BitcoinExchange::BitcoinExchange(const char* input_file_name) {
	this->data_file_.open("data.csv", std::ios::in);
	if (!this->data_file_.is_open()) {
		throw (CouldNotOpenFileException());
	}
	this->input_file_.open(input_file_name, std::ios::in);
	if (!this->input_file_.is_open()) {
		throw (CouldNotOpenFileException());
	}
}

BitcoinExchange::~BitcoinExchange(void) {
	if (this->data_file_.is_open()) {
		this->data_file_.close();
	}
	if (this->input_file_.is_open()) {
		this->input_file_.close();
	}
}

const std::ifstream& BitcoinExchange::getDataIfstream(void) const {
	return (this->data_file_);
}
const std::ifstream& BitcoinExchange::getInputIfstream(void) const {
	return (this->input_file_);
}

int BitcoinExchange::fill_data_(void) {
	std::string date;
	if (!this->data_file_.is_open()) {
		throw (CouldNotOpenFileException());
	}
	if (!std::getline(this->data_file_, date)) {
		return (1);
	}
	while (this->data_file_.is_open() && std::getline(this->data_file_, date) {
		
	}
	return (0);
}


// -------------- Exceptions -------------------

const char* BitcoinExchange::CouldNotOpenFileException::what(void) const throw() {
	return ("Error: could not open file.");
}

const char* BitcoinExchange::ErrorInDataException::what(void) const throw() {
	return ("Error: error in data.csv file");
}

const char* BitcoinExchange::NotAPositiveNumber::what(void) const throw() {
	return ("Error: not a positive number.");
}

const char* BitcoinExchange::TooLargeNumber::what(void) const throw() {
	return ("Error: too large a number.");
}
