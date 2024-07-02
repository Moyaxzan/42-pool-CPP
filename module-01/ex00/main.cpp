#include "Zombie.hpp"
#include <iostream>

int main() {
	std::cout << "Zombie on the heap :" << std::endl;
	Zombie	*zombie1 = newZombie("Adam");
	if (zombie1) {
		zombie1->announce();
		delete (zombie1);
	}

	std::cout << "Zombie on the stack in the main function :" << std::endl;
	Zombie	zombie2("Eve");
	zombie2.announce();

	std::cout << "Zombie on the stack :" << std::endl;
	randomChump("Sin");

	return (0);
}
