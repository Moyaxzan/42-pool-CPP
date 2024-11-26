#include "Span.hpp"
#include <exception>
#include <iostream>
#include <vector>

int main(void)
{
	{
		std::cout << "--------Suject--------" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << std::endl <<"--------Errors--------" << std::endl;
		Span sp = Span(1);
		try {
			sp.addNumber(1);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			sp.addNumber(2);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl; // error: span.size is 1 (trying to add 2nd nb)
		}
		try {
			std::cout << sp.shortestSpan() << std::endl; // error: only 1 element
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << sp.longestSpan() << std::endl; // error: only 1 element
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "----------Fill--------" << std::endl;
		std::vector<int> vec(100);
		for (int i = 0; i < 100; i++) {
			vec[i] = i;
		}
		Span sp = Span(100);
		sp.fill(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl; // 1 (distance between every elem)
		std::cout << sp.longestSpan() << std::endl;  // 99 (99 - 0)
	
		std::cout << std::endl << "-------Fail Fill------" << std::endl;
		std::cout << std::endl;
		std::vector<int> vect(200);
		for (int i = 0; i < 200; i++) {
			vect[i] = i;
		}
		Span span = Span(100);
		try {
			span.fill(vect.begin(), vect.end()); // vect.size = 200 && span.size = 100 -> overflow
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl << "-----<< operator -----" << std::endl;
		std::cout << sp << std::endl;
	}
	{
		std::cout << std::endl << "--------200 000-------" << std::endl;
		Span sp = Span(200000);
		for (int i = 0; i < 200000; i++) {
			sp.addNumber(i);
		}
		std::cout << sp.shortestSpan() << std::endl; // 1 (distance between every elem)
		std::cout << sp.longestSpan() << std::endl;  // 199 999
	}
	return 0;
}
