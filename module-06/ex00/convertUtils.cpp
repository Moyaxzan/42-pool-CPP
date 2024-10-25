#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <sstream>

bool isSign(int c) { return (c == '-' || c == '+'); }

int isChar(std::string str) {
	if (str.length() == 1) {
		return (ISCHAR);
	}
	return (0);
}

int isFltorDbl(std::string str) {
	int i = 0;
	bool has_dot = false;

	if (isSign(str[i])) {
		i++;
	}
	while (str[i] && (isdigit(str[i]) || (!has_dot && i > 0 && str[i] == '.' && !isSign(str[i - 1])))) {
		if (str[i] == '.') {
			has_dot = true;
		}
		i++;
	}
	if (has_dot && i > 2 && str[i] == 'f' && !str[i + 1] && isdigit(str[i - 1])) {
		return (ISFLOAT);
	} else if (has_dot && i > 2 && isdigit(str[i - 1]) && !str[i]) {
		return (ISDOUBLE);
	}
	return (0);
}

int isInt(std::string str) {
	int	i = 0;

	if (str[i] == '-' || str[i] == '+') {
		i++;
	}
	while (str[i] && isdigit(str[i])) {
		i++;
	}
	if (i < 1 || str[i]) {
		return (0);
	}
	return (ISINT);
}


void convertFromChar(std::string str) {
	std::cout << "char: " << "'" << str[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void convertFromInt(std::string str) {
	std::stringstream strs(str);
	int val;
	strs >> val;

	if (val < 32 || val > 126) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: " << "'" << static_cast<char>(val) << "'" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(val) << std::endl;
	if (static_cast<double>(val) >= 1e6) {
		std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << "" << std::endl;
	} else {
		std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
	}
}

void convertFromFloat(std::string str) {
	std::stringstream strs(str);
	float val;
	strs >> val;

	if (val < 32 || val > 126) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: " << "'" << static_cast<char>(val) << "'" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(val) << std::endl;
	if (val - static_cast<int>(val) || static_cast<double>(val) >= 1e6) {
		std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << "" << std::endl;
	} else {
		std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
	}
}

void convertFromDouble(std::string str) {
	std::stringstream strs(str);
	double val;
	strs >> val;

	if (val < 32 || val > 126) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: " << "'" << static_cast<char>(val) << "'" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(val) << std::endl;
	if (val - static_cast<int>(val) || static_cast<double>(val) >= 1e6) {
		std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << "" << std::endl;
	} else {
		std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
	}
}
