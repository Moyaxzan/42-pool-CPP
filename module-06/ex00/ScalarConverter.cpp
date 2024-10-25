#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter& other) {
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other) {
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

void ScalarConverter::convert(std::string str) {
	convertChar(str);
	convertInt(str);
	convertFloat(str);
	convertDouble(str);
}
