#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
	try {
		if (argc < 2) {
			throw (BitcoinExchange::CouldNotOpenFileException());
		}
		BitcoinExchange btc(argv[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
