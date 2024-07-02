#include "Zombie.hpp"
#include <iostream>

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0 || N > 2147483647) {
		std::cout << "invalid integer." << std::endl;
		return (NULL);
	}
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].set_name(name);
	}
	return (horde);
}
