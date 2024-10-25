#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter& other);
		ScalarConverter& operator=(ScalarConverter& other);
		~ScalarConverter();

		static void convert(std::string);
};

#endif
