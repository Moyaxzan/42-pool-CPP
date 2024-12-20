#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <exception>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange {
	public:
		// CANONICAL FORM
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(BitcoinExchange& other);
		~BitcoinExchange(void);

		// GETTERS / SETTERS
		const std::ifstream& getDataIfstream(void) const;

		// DEBUG FUNCTIONS
		void printData(void) const;

		// EXCEPTIONS
		class CouldNotOpenFileException : public std::exception {
			public:
				const char* what(void) const throw();
		};

		class ErrorInDataException : public std::exception {
			const char* what(void) const throw();
		};

		class ErrorInInputException : public std::exception {
			public:
				const char* what(void) const throw();
		};

		class NotAPositiveNumber : public std::exception {
			const char* what(void) const throw();
		};

		class TooLargeNumber : public std::exception {
			const char* what(void) const throw();
		};
		
		// MEMBER FUNCTIONS
		void displayExchange(std::string input);

	private:
		std::ifstream data_file_;
		std::map<std::string, double> data_;

		int fill_data_(void);
		bool validDateFormat_(std::string date) const;
		double strToDbl(std::string str);
};

#endif
