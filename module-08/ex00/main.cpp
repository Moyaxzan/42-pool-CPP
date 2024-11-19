#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <list>
#include <vector>

int main(void) {
	// vectors
	{
		std::vector<int> vect(10);
		for (int i = 0; i < 10; i++) {
			vect.push_back(i);
		}
		try {
			easyfind(vect, 9);
			std::cout << "9 found in vect" << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(vect, 12);
			std::cout << "12 found in vect" << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	// lists
	{
		std::list<int> list(10);
		for (int i = 0; i < 10; i++) {
			list.push_back(i * 2);
		}
		try {
			easyfind(list, 12);
			std::cout << "12 found in list" << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(list, 9);
			std::cout << "9 found in list" << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
