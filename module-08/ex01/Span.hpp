#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <istream>
#include <vector>
class Span {
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span& other);
		~Span(void);
		
		Span& operator=(const Span& other);

		unsigned int getSize(void) const;
		const std::vector<int>& getVect(void) const;

		void addNumber(int number);
		int shortestSpan(void) const;
		int longestSpan(void) const;

		class SpanOverflowException : public std::exception {
			const char* what() const throw() { return ("Error: span is already full"); }
		};

		class NotEnoughNumbersException : public std::exception {
			const char* what() const throw() { return ("Error: not enough numbers to get span"); }
		};

	private:
		unsigned int _size;
		std::vector<int> _vect;
};

const std::ostream& operator<<(const std::ostream& os, const Span& span);

#endif
