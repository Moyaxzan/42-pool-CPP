#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# define ISDOUBLE 0b1
# define ISFLOAT 0b10
# define ISINT 0b100
# define ISCHAR 0b1000


class ScalarConverter {
	public:
		static void convert(std::string);

	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter& other);
		ScalarConverter& operator=(ScalarConverter& other);
		~ScalarConverter();
};

int isChar(std::string str);
int isFltorDbl(std::string str);
int isInt(std::string str);
int convertSpecial(std::string str);

void convertFromChar(std::string str);
void convertFromInt(std::string str);
void convertFromFloat(std::string str);
void convertFromDouble(std::string str);

#endif
