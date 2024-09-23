#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

//CONSTRUCTORS ----------------------------------------------------//

FragTrap::FragTrap(std::string ft_name) : ClapTrap(ft_name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "Hi, I'm " << name << " FragTrap, reporting for duty!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.name) { 
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	this->hitPoints = other.hitPoints;
	this->name = other.name;
}

FragTrap::~FragTrap() {
	std::cout << "I hope " << name << " has been usefull enough, bye..." << std::endl;
}

//OPERATORS ----------------------------------------------------//

FragTrap	&FragTrap::operator=(const FragTrap &other) {
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	this->hitPoints = other.hitPoints;
	this->name = other.name;
	return (*this);
}

//MEMBER FUNCTIONS ----------------------------------------------------//

void	FragTrap::attack(std::string target) {
	if (!this->hitPoints) {
		std::cout << "FragTrap " << this->name << " has no more hit points" << std::endl;
		return ;
	}
	if (!this->energyPoints) {
		std::cout << "FragTrap " << this->name << " has no more energy points" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "FragTrap  " << this->name << ": attacking " << target << "!";
	std::cout << " I dealt " << this->attackDamage << " points of damages!" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name << ": give me a high five !" << std::endl;
}
