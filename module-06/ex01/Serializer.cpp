#include "Serializer.hpp"
#include <sys/_types/_uintptr_t.h>

Serializer::Serializer(void) {}

Serializer::Serializer(Serializer &other) {
	*this = other;
}

Serializer& Serializer::operator=(Serializer& other) {
	(void) other;
	return (*this);
}

Serializer::~Serializer(void) {}


uintptr_t Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
