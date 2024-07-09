#include "Point.hpp"


Point::Point(void) {
	this->_x = Fixed(0);
	this->_y = Fixed(0);
}

Point::~Point(void) {
}

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y) {
}

Point::Point(const Point &other) {
	this->_x.setRawBits(other._x.getRawBits());
	this->_y.setRawBits(other._y.getRawBits());
}

Point &Point::operator=(const Point &other) {
	if (this != &other) {
		this->_x.setRawBits(other._x.getRawBits());
		this->_y.setRawBits(other._y.getRawBits());
	}
	return (*this);
}

Fixed	Point::get_x() const {
	return (this->_x);
}

Fixed	Point::get_y() const {
	return (this->_y);
}

void	Point::set_x(Fixed const x) {
	this->_x = x;
}

void	Point::set_y(Fixed const y) {
	this->_y = y;
}
