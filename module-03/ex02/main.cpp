#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	FragTrap frager("frager");

	frager.attack("le Martien de Venus");
	frager.highFivesGuys();
	frager.takeDamage(99);
	frager.beRepaired(1);
	frager.takeDamage(2);
	//no more life
	frager.beRepaired(5);
	frager.highFivesGuys();
}
