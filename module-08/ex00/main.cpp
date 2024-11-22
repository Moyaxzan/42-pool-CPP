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
			if (easyfind(vect, 9)) {
				std::cout << "9 found in vect" << std::endl;
			} else {
				std::cout << "9 not fount in vect" << std::endl;
			}
			if (easyfind(vect, 12)) {
				std::cout << "12 found in vect" << std::endl;
			} else {
				std::cout << "12 not found in vect" << std::endl;		
			}
	}

	// lists
	{
		std::list<int> list(10);
		for (int i = 0; i < 10; i++) {
			list.push_back(i * 2);
		}
		if (easyfind(list, 12)) {
			std::cout << "12 found in list" << std::endl;
		} else {
			std::cout << "12 not found in list" << std::endl;
		}
		if (easyfind(list, 9)) {
			std::cout << "9 found in list" << std::endl;
		} else {
			std::cout << "9 not found in list" << std::endl;
		}
	}
	return (0);
}
