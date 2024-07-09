#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _fixedValue(0) {
}

Fixed::Fixed(const int integer): _fixedValue(integer << this->_nbFractBits) {
}

Fixed::Fixed(const float floating): _fixedValue(roundf((1 << this->_nbFractBits) * floating)) {
}

Fixed::~Fixed(void) {
}

Fixed::Fixed (const Fixed &other) {
	this->setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->setRawBits(other.getRawBits());
	}
	return (*this);
}

bool	Fixed::operator<(const Fixed &other) const {
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator<=(const Fixed &other) const {
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator>(const Fixed &other) const {
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator>=(const Fixed &other) const {
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator==(const Fixed &other) const {
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed &other) const {
	return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator+(const Fixed &other) const {
	return (this->toFloat() + other.toFloat());
}   
  
Fixed Fixed::operator-(const Fixed &other) const {
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed res;
    long long temp = static_cast<long long>(this->_fixedValue) << this->_nbFractBits;

    if (temp >= 0)
        temp += other._fixedValue / 2;
    else
        temp -= other._fixedValue / 2;
    res.setRawBits(temp / other._fixedValue);
    return res;
}

Fixed	&Fixed::operator++(void) {
	this->_fixedValue++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	this->_fixedValue++;
	return (temp);
}

Fixed	&Fixed::operator--(void) {
	this->_fixedValue--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	this->_fixedValue--;
	return (temp);
}

Fixed const	&Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

Fixed const	&Fixed::min(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (b);
	return (a);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

Fixed 	&Fixed::min( Fixed &a, Fixed &b) {
	if (a > b)
		return (b);
	return (a);
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
