#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <string>

int main() {
	DiamondTrap diamondtrap("Diamond");
	diamondtrap.attack("Emerald");
	diamondtrap.takeDamage(25);
	diamondtrap.beRepaired(10);
	diamondtrap.takeDamage(100);
	diamondtrap.attack("Emerald");
	diamondtrap.beRepaired(100);
	diamondtrap.whoAmI();
	return 0;
}
