#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

//CONSTRUCTORS ----------------------------------------------------//

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other._type) {
}

WrongCat::~WrongCat() {
}

//OPERATORS ----------------------------------------------------//

WrongCat	&WrongCat::operator=(const WrongCat &other) {
	this->_type = other._type;
	return (*this);
}

//MEMBER FUNCTIONS ----------------------------------------------------//
