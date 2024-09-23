#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	 ScavTrap big_robot("big_robot");
	 ScavTrap the_beast("the_beast");
	 ClapTrap scraps("scraps");
	{
	 big_robot.attack(scraps.getName());
	 scraps.takeDamage(big_robot.getAttackDamages());
	 big_robot.takeDamage(1);
	 big_robot.beRepaired(1);
	 big_robot.guardGate();
	 big_robot.guardGate();
	}
 	{
	 the_beast.attack(big_robot.getName());
	 big_robot.takeDamage(the_beast.getAttackDamages());
	 the_beast.guardGate();
	 the_beast.beRepaired(5);
	 scraps.attack(big_robot.getName());
	 big_robot.takeDamage(scraps.getAttackDamages());
	 scraps.attack(the_beast.getName());
	 the_beast.takeDamage(scraps.getAttackDamages());
	}

}
