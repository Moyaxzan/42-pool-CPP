#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	ScalarConverter converter;

	if (argc > 1) {
		converter.convert(argv[1]);
	}
	return (0);
}
