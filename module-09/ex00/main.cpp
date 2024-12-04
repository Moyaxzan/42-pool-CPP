#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

bool get_file_line(const char* file_name, std::ifstream &input_file, std::string &input_line) {
	if (!input_file.is_open()) {
		input_file.open(file_name, std::ios::in);
		if (!input_file.is_open()) {
			throw (BitcoinExchange::CouldNotOpenFileException());
		}
	}
	if (!std::getline(input_file, input_line))
		return (false);
	return (true);
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
		get_file_line(argv[1], input_file, input_line);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	while (!input_file.eof() || input_file.fail()) {
		try {
			if (!get_file_line(argv[1], input_file, input_line)) {
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
