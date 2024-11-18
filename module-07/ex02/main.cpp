#include "Array.hpp"
#include <exception>
#include <iostream>
#include <string>

// int main(void) {
// 	// int * a = new int();
// 	// std::cout << *a << std::endl;
// 	try {
// 		Array<int> empty;
// 		std::cout << empty[0] << std::endl;
// 	} catch (std::exception &e) {
// 		std::cerr << e.what() << std::endl;
// 	}
//
// 	try {
// 		Array<int> arre(10);
// 		std::cout << arre[1] << std::endl;
// 		std::cout << arre[9] << std::endl;
// 		arre[2] = 10;
// 		std::cout << arre[2] << std::endl;
// 	} catch (std::exception &e) {
// 		std::cerr << e.what() << std::endl;
// 	}
//
// 	try {
// 		Array<std::string> arre2(3);
// 		// ascii code of '*' is 42 (default value)
// 		std::cout << arre2[2] << std::endl;
// 		arre2[1] = 'a';
// 		std::cout << arre2[1] << std::endl;
// 	} catch (std::exception &e) {
// 		std::cerr << e.what() << std::endl;
// 	}
//
// 	return (0);
// }
#include<cstdlib>
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
		std::cout << numbers[i] << " ";
    }
	std::cout << std::endl;
    delete [] mirror;//
    return 0;
}
