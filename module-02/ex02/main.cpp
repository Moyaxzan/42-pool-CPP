#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;	
	}
	{
		Fixed a(42);
		Fixed b(70);
		Fixed c(12.3f);
		std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;

		std::cout << "MAX AND MIN" << std::endl;
		std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
		std::cout << "max(a, c) = " << Fixed::max(a, c) << std::endl;
		std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;
		std::cout << "min(a, c) = " << Fixed::min(a, c) << std::endl;

		std::cout << "INCREMENTATION" << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "++a = " << ++a << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "b++ = " << b++ << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "--a = " << --a << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "b-- = " << b-- << std::endl;
		std::cout << "b = " << b << std::endl;

		std::cout << "COMPARISONS" << std::endl;
		std::cout << "a > b " << (a > b) << std::endl;
		std::cout << "a == c  " << (a == c) << std::endl;
		std::cout << "a < b " << (a < b) << std::endl;
		std::cout << "b != c  " << (b != c) << std::endl;
		std::cout << "a >= b " << (a >= b) << std::endl;
		std::cout << "a <= b " << (a <= b) << std::endl;
		std::cout << "b == b " << (b == b) << std::endl;

		std::cout << "OPERATIONS" << std::endl;
		std::cout << "a + b " << (a + b) << std::endl;
		std::cout << "b + c " << (b + c) << std::endl;
		std::cout << "b - c " << (b - c) << std::endl;
		std::cout << "a * b " << (a * b) << std::endl;
		std::cout << "b / a  " << (b / a) << std::endl;
	}
	return 0;
}
