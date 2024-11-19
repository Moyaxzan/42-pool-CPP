#include "Span.hpp"
#include <algorithm>

Span::Span(void) {
	this->_size = 0;
}

Span::Span(unsigned int N) : _size(N), _vect(N) {}

Span::Span(const Span& other) : _size(other._size), _vect(other._vect){}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_vect = other._vect;
		this->_size = other._size;
	}
	return (*this);
}

Span::~Span(void) {}


unsigned int Span::getSize(void) const { return (this->_size); }

const std::vector<int> & Span::getVect(void) const { return (this->_vect); }

void Span::addNumber(int number) {
	if (this->_vect.size() > this->_size) {
		throw SpanOverflowException();
	}
	this->_vect.push_back(number);
}

//TODO: implement addLotsOfNumber

int Span::shortestSpan(void) const {
	if (this->_vect.size() < 3) {
		throw NotEnoughNumbersException();
	}
	std::vector<int> sorted(this->_vect);
	std::sort(sorted.begin(), sorted.end());
	int shortest_span = sorted[1] - sorted[0];
	for (unsigned int i = 1; i < (this->_vect.size() - 1); i++) {
		if (shortest_span > (sorted[i + 1] - sorted[i])) {
			shortest_span = sorted[i + 1] - sorted[i];
		}
	}
	return (shortest_span);
}

int Span::longestSpan(void) const {
	if (this->_vect.size() < 3) {
		throw NotEnoughNumbersException();
	}
	return (std::max_element(this->_vect.begin(), this->_vect.end()) - std::min_element(this->_vect.begin(), this->_vect.end()));
}

//TODO: implement << operator overload to print span
