#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "Hi, I'm " << name << " ScavTrap, reporting for duty!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.name) { 
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	this->hitPoints = other.hitPoints;
	this->name = other.name;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other) {
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	this->hitPoints = other.hitPoints;
	this->name = other.name;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "I hope " << name << " has been usefull enough, bye..." << std::endl;
}

void	ScavTrap::attack(std::string target) {
	if (!this->hitPoints) {
		std::cout << "ScavTrap " << this->name << " has no more hit points" << std::endl;
		return ;
	}
	if (!this->energyPoints) {
		std::cout << "ScavTrap " << this->name << " has no more energy points" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ScavTrap  " << this->name << ": attacking " << target << "!";
	std::cout << " I dealt " << this->attackDamage << " points of damages!" << std::endl;
}

void	ScavTrap::guardGate(void) {
		std::cout << "ScavTrap " << this->name << ": I'm now a gate keeper!" << std::endl;
}
