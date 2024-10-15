#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void): AMateria("ice") {}

Ice::Ice(const Ice& other): AMateria(other._type) {}

Ice&	Ice::operator=(const Ice& other) {
	this->_type = other._type;
	return (*this);
}

Ice::~Ice(void) {}

AMateria*	Ice::clone(void) const {
	return (new Ice(*this));
}
