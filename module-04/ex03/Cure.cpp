#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void): AMateria("cure") {}

Cure::Cure(const Cure& other): AMateria(other._type) {}

Cure&	Cure::operator=(const Cure& other) {
	this->_type = other._type;
	return (*this);
}

Cure::~Cure(void) {}

AMateria*	Cure::clone(void) const {
	return (new Cure(*this));
}
