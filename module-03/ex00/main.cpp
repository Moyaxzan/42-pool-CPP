#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap	roger("Roger");

	roger.takeDamage(5);
	roger.beRepaired(1);
	roger.attack("Federrer");
	roger.beRepaired(1);
	roger.attack("Federrer");
	roger.beRepaired(1);
	roger.attack("Federrer");
	roger.beRepaired(1);
	roger.beRepaired(1);
	roger.takeDamage(5);
	roger.beRepaired(1);
	roger.attack("Federrer");
	roger.beRepaired(1);
	roger.takeDamage(10);
	roger.attack("Federrer");
	roger.beRepaired(1);
}
