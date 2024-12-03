#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

std::string get_file_line(const char* file_name, std::ifstream &input_file) {
	if (!input_file.is_open()) {
		input_file.open(file_name, std::ios::in);
		if (!input_file.is_open()) {
			throw (BitcoinExchange::CouldNotOpenFileException());
		}
	}
	std::string res;
	std::getline(input_file, res);
	return (res);
}

int main(int argc, char *argv[]) {
	BitcoinExchange btc; // throwing error ???
	try {
		if (argc < 2) {
			throw (BitcoinExchange::CouldNotOpenFileException());
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	std::ifstream input_file;
	std::string input_line;
	try {
		input_line = get_file_line(argv[1], input_file);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	while (input_line.length() > 0) {
		try {
			input_line = get_file_line(argv[1], input_file);
			if (input_line.length() <= 0) {
				break;
			}
			btc.displayExchange(input_line);
		} catch (BitcoinExchange::CouldNotOpenFileException &e) {
			std::cerr << e.what() << std::endl;
			return (1);
		} catch (std::exception &ex) {
			std::cerr << ex.what() << std::endl;
		}
	}
	input_file.close();
	return (0);
}
