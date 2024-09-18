#include "ClapTrap.hpp"
#include <iostream>
#include <string>

//CONSTRUCTORS ----------------------------------------------------//

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
}

//OPERATORS ----------------------------------------------------//
ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap assignment operator called" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

//GETTERS SETTERS ----------------------------------------------------//

std::string		ClapTrap::getName(void) {
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints(void) {
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) {
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamages(void) {
	return (this->attackDamage);
}

//MEMBER FUNCTIONS ----------------------------------------------------//

void	ClapTrap::attack(const std::string& target) {
	if (!this->hitPoints) {
		std::cout << "ClapTrap " << this->name << " has no more hit points" << std::endl;
		return ;
	}
	if (!this->energyPoints) {
		std::cout << "ClapTrap " << this->name << " has no more energy points" << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= this->hitPoints) {
		this->hitPoints = 0;
	} else {
		this->hitPoints -= amount;
	}
	std::cout << "ClapTrap " << this->name << " took " << amount << " damages!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->hitPoints) {
		std::cout << "ClapTrap " << this->name << " has no more hit points" << std::endl;
		return ;
	}
	if (!this->energyPoints) {
		std::cout << "ClapTrap " << this->name << " has no more energy points" << std::endl;
		return ;
	}
	if (amount + this->hitPoints >= 10) {
		this->hitPoints = 10;
	} else {
		this->hitPoints += amount;
	}
	this->energyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " has been repared by ";
	std::cout << amount << " hit points!" << std::endl;
}
