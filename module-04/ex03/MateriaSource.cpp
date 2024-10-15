#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) {
	for(int i = 0; i < 4; i++) {
		this->_stock[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource& other) {
	for (int i= 0; i < 4; i++) {
		if (other._stock[i]) {
			this->_stock[i] = other._stock[i]->clone();
		} else {
			this->_stock[i] = NULL;
		}
	}
}

MateriaSource&	MateriaSource::operator=(MateriaSource& other) {
	this->deleteStock();
	for (int i = 0; i < 4; i++) {
		if (other._stock[i]) {
			this->_stock[i] = other._stock[i]->clone();
		} else {
			this->_stock[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	this->deleteStock();
}


void	MateriaSource::deleteStock(void) {
	for (int i = 0; i < 4; i++) {
		if (this->_stock[i]) {
			delete this->_stock[i];
			this->_stock[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria* m) {
	int	i = 0;

	while (this->_stock[i] && i < 4) {
		i++;
	}
	if (i < 4) {
		this->_stock[i] = m;
	} else {
		std::cout << "equip: inventory already full" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	if (!type.size())
		return (NULL);
	for (int i = 0; i < 4; i++) {
		if (this->_stock[i] && this->_stock[i]->getType() == type) {
			return (this->_stock[i]->clone());
		}
	}
	return (NULL);
}
