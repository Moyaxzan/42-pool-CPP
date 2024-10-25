#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	ScalarConverter converter;

	if (argc > 1) {
		converter.convert(argv[1]);
	}
	return (0);

	// std::string str = "350282300000000000000000000000000000000,10";
    // Converting string to float 
    // float str_float = static_cast<float>(atof(str.c_str())); 
  
    // Converting string to double 
 //    double str_double = static_cast<double>(atof(str.c_str())); 
 //  
	// std::cout<< "string as float = " << str_float << std::endl; 
	// std::cout<< "string as double = " << str_double << std::endl;
}
