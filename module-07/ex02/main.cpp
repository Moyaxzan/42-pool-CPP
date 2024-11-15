#include "Array.hpp"
#include <exception>
#include <iostream>
#include <string>

int main(void) {
	// int * a = new int();
	// std::cout << *a << std::endl;
	try {
		Array<int> empty;
		std::cout << empty[0] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Array<int> arre(10);
		std::cout << arre[1] << std::endl;
		std::cout << arre[9] << std::endl;
		arre[2] = 10;
		std::cout << arre[2] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Array<std::string> arre2(3);
		// ascii code of '*' is 42 (default value)
		std::cout << arre2[2] << std::endl;
		arre2[1] = 'a';
		std::cout << arre2[1] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
