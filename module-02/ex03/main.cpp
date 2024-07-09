#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point	a(Fixed(1), Fixed(5));
	Point	b(Fixed(3), Fixed(4));
	Point	c(Fixed(4), Fixed(0));
	Point	p(Fixed(3), Fixed(3));
	Point	q(Fixed(2), Fixed(3.5f));
	Point	s(Fixed(2), Fixed(3));

	std::cout << "p in triangle : " << insideTriangle(p, a, b, c) << std::endl;
	std::cout << "q in triangle : " << insideTriangle(q, a, b, c) << std::endl;
	std::cout << "s in triangle : " << insideTriangle(s, a, b, c) << std::endl;
	return (0);
}
