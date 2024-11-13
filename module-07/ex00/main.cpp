#include "whatever.hpp"
#include <iostream>

// a = 3, b = 2
// a = 5, b = 2
// a = 5, b = 3
// a = 2, b = 3
template <typename T> void swap(T& p1, T& p2) {
	T tmp = p1;
	p1 = p2;
	p2 = tmp;
	return ;
}

template <typename T> T min(T &a, T &b) {
	if (a < b) {
		return (a);
	}
	return (b);
}

template <typename T> T max(T &a, T &b) {
	if (a > b) {
		return (a);
	}
	return (b);
}

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
