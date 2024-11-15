#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T> void iter(T* array, unsigned long len, void (*fct)(T& elem)) {
	for (long unsigned int i = 0; i < len; i++) {
		fct(array[i]);
	}
}

template<typename T> void iter(T* array, unsigned long len, void (*fct)(const T& elem)) {
	for (unsigned long int i = 0; i < len; i++) {
		fct(array[i]);
	}
}

template<typename T> void print_elem(const T& elem) {
	std::cout << elem << "\t";
}

#endif // !ITER_HPP
