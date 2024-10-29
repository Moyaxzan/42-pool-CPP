#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

//It randomly instanciates A, B or C and returns the instance as a Base pointer.
//Feel free to use anything you like for the random choice implementation.
Base* generate(void) {
	int val = std::rand() % 3;
	Base* res;

	if (val == 0) {
		res = new A;
	} else if (val == 1) {
		res = new B;
	} else {
		res = new C;
	}
	return (res);
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p){
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "unknown type" << std::endl;
	}
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C".
//Using a pointer inside this function is forbidden.
// void identify(Base& p){
// 
// }

int main(void) {
	std::srand(std::time(0));
	Base *base;

	for (int i = 0; i < 100; i++) {
		base = generate();
		identify(base);
		delete base;
	}
}