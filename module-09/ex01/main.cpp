#include "RPN.hpp"
#include <exception>
#include <iostream>
#include <algorithm>
#include <string>

void removeWhitspaces(std::string &str) {
	str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::string arg(argv[1]);
	removeWhitspaces(arg);
	RPN rpn;
	try {
		for (std::string::iterator it = arg.begin(); it != arg.end(); it++) {
			rpn.makeOperation(*it);
		}
		std::cout << rpn.getResult() << std::endl;
	} catch (std::exception &e) {
		(void) e;
		std::cerr << "Error" << std::endl;
	}
	return (0);
}
