#include "Iter.hpp"

int main(void) {
	int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	float array2[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	char array3[] = {'$', '%', '(', ')', '+', '-'};
	int array4[] = {};
	void* array5[] = {array1, array2, array3, array4};

	iter(array1, 9, print_elem);
	std::cout << std::endl;
	iter(array2, 5, print_elem);
	std::cout << std::endl;
	iter(array3, 6, print_elem);
	std::cout << std::endl;
	iter(array4, 0, print_elem);
	std::cout << std::endl;
	iter(array5, 4, print_elem);
	std::cout << std::endl;
	return (0);
}
