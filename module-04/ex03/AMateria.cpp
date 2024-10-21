#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) {
	this->_type = type;
}

AMateria::AMateria(const AMateria &other) {
	this->_type = other._type;
}

AMateria& AMateria::operator=(const AMateria &other) {
	this->_type = other._type;
	return (*this);
}

AMateria::~AMateria(void) {}

std::string	const & AMateria::getType(void) const {
	return (this->_type);
}

void		AMateria::use(ICharacter& target) {
	(void) target;
	std::cout << "use: no materia set." << std::endl;
}
