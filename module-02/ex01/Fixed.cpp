#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer): _fixedValue(integer << this->_nbFractBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floating): _fixedValue(roundf((1 << this->_nbFractBits) * floating)) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
}

Fixed &Fixed::operator = (const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

int	Fixed::getRawBits(void) const {
	return (this->_fixedValue);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedValue = raw;
}

int	Fixed::toInt(void) const {
	return (this->_fixedValue >> this->_nbFractBits);
}

float	Fixed::toFloat(void) const {

	return (this->_fixedValue / float(1 << this->_nbFractBits));
}
