#include "Serializer.hpp"
#include <iostream>

int main(void) {
	Data data;

	data.value = 150;
	std::cout << "&data = " << &data << std::endl;
	std::cout << "data.value = " << data.value << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "raw = " << raw << std::endl;

	Data* ptr = Serializer::deserialize(raw);
	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "ptr->value = " << ptr->value << std::endl;
}
