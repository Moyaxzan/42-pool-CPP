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
	int type = 0;

	if (convertSpecial(str)) {
		return ;
	} else if ((type = isInt(str))) {
		return (convertFromInt(str));
	} else if ((type = isChar(str))) {
		return (convertFromChar(str));
	} else if ((type = isFltorDbl(str))) {
		if (type == ISDOUBLE) {
			return (convertFromDouble(str));
		} else {
			return (convertFromFloat(str));
		}
	}
}
