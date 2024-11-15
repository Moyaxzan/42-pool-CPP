#include "whatever.hpp"
#include <iostream>

int main(void) {
	char a = 'a', b = 'b';
	int c = 123, d = 987;
	float e = 0.333f, f = 7.77f;
	int *g = &c, *h = &d;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "--------------SWAP--------------" << std::endl;
	swap(a, b);
	swap(c, d);
	swap(e, f);
	swap(g, h);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "--------------MIN---------------" << std::endl;
	std::cout << "min('" << a << "', '" << b << "') = " << min(a, b) << std::endl;
	std::cout << "min(" << c << ", " << d << ") = " << min(c, d) << std::endl;
	std::cout << "min(" << e << ", " << f << ") = " << min(e, f) << std::endl;
	std::cout << "min(" << g << ", " << h << ") = " << min(g, h) << std::endl;
	std::cout << "--------------MAX---------------" << std::endl;
	std::cout << "max('" << a << "', '" << b << "') = " << max(a, b) << std::endl;
	std::cout << "max(" << c << ", " << d << ") = " << max(c, d) << std::endl;
	std::cout << "max(" << e << ", " << f << ") = " << max(e, f) << std::endl;
	std::cout << "max(" << g << ", " << h << ") = " << max(g, h) << std::endl;
	return (0);
}
