#include "Zombie.hpp"

int main() {
	int	N = 10;

	Zombie	*horde = zombieHorde(N, "aaarrrrrgghhhh");
	if (!horde) {
		return (1);
	}
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	return (0);
}
