#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

//CONSTRUCTORS ----------------------------------------------------//

DiamondTrap::DiamondTrap(std::string dt_name) : ClapTrap(dt_name + "_clap_name"), ScavTrap(dt_name), FragTrap(dt_name) {
	this->name = dt_name;
	this->hitPoints = FRAGTRAP_HP;
	this->energyPoints = SCAVTRAP_EP;
	this->attackDamage = FRAGTRAP_AD;
	std::cout << "Hi, I'm " << name << " DiamondTrap, reporting for duty!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.name + "_clap_name"), ScavTrap(other.name), FragTrap(other.name){
	this->name = other.name;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	this->hitPoints = other.hitPoints;
	this->name = other.name;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "I hope " << name << " has been usefull enough, bye..." << std::endl;
}

//OPERATORS ----------------------------------------------------//

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other) {
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	this->hitPoints = other.hitPoints;
	this->name = other.name;
	return (*this);
}

//MEMBER FUNCTIONS ----------------------------------------------------//

void	DiamondTrap::attack(std::string target) {
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "whoAmI DiamondTrap name : " << this->name;
	std::cout << ", ClapTrap name : " << this->ClapTrap::name << std::endl;
}
