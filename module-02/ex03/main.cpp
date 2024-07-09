#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point	a(1, 5);
	Point	b(3, 4);
	Point	c(4, 0);
	Point	p(3, 3);
	Point	q(2, 3.5f);
	Point	s(2, 3);

	std::cout << "p in triangle : " << insideTriangle(p, a, b, c) << std::endl;
	std::cout << "q in triangle : " << insideTriangle(q, a, b, c) << std::endl;
	std::cout << "s in triangle : " << insideTriangle(s, a, b, c) << std::endl;
	return (0);
}
