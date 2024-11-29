#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>


BitcoinExchange::BitcoinExchange(void) {
	this->data_file_.open("data.csv", std::ios::in);
	if (!this->data_file_.is_open()) {
		throw (CouldNotOpenFileException());
	}
	fill_data_();
}

BitcoinExchange::~BitcoinExchange(void) {
	if (this->data_file_.is_open()) {
		this->data_file_.close();
	}
}

const std::ifstream& BitcoinExchange::getDataIfstream(void) const {
	return (this->data_file_);
}

int BitcoinExchange::fill_data_(void) {
	if (!this->data_file_.is_open()) {
		throw (CouldNotOpenFileException());
	}
	std::string date;
	std::string btc_value;
	if (!std::getline(this->data_file_, date)) {
		return (1);
	}
	char *val_str_end;
	while (this->data_file_.is_open() && std::getline(this->data_file_, date, ',')) {
		if (!this->validDateFormat_(date)) {
			throw (ErrorInDataException());
		}
		std::getline(this->data_file_, btc_value);
		btc_value[btc_value.length()] = '\0';
		this->data_[date] = std::strtod(btc_value.c_str(), &val_str_end);
		if (*val_str_end != '\0') {
			throw (ErrorInDataException());
		}
	}
	this->printData();
	return (0);
}

bool BitcoinExchange::validDateFormat_(std::string date) const {
	if (date.length() != 10) {
		return (false);
	}
	for (size_t i = 0; i < date.length(); i++) {
		if (i == 4 || i == 7) {
			if (date[i] != '-') {
				return (false);
			}
		} else {
			if (!std::isdigit(date[i])) {
				return (false);
			}
		}
	}

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
	if (std::strcmp(date.c_str(), "2022-03-29") > 0) {
		return (false);
	}
	if (month < 1 || month > 12 || day < 1 || day > 31) {
		return (false);
	} else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) {
		return (false);
	} else if (month == 2) {
		bool isLeapYear = (year % 4 == 0 && ((year % 100) || !(year % 400)));
		if (day > 28 + isLeapYear) {
			return (false);
		}
	}
	return (true);
}

void BitcoinExchange::printData(void) const {
	for (std::map<std::string, double>::const_iterator it = this->data_.begin(); it != this->data_.end(); it++) {
		std::cout << it->first << " ------> " << it->second << std::endl;
	}
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
