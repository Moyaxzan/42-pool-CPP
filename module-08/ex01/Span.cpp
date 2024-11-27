#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

Span::Span(void) {
	this->_size = 0;
	this->_vect = std::vector<int>(0);
}

Span::Span(unsigned int N) : _size(N){}

Span::Span(const Span& other) : _size(other._size), _vect(other._vect){}

Span::~Span(void) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_vect = other._vect;
		this->_size = other._size;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Span& span) {
	if (os) {
		std::vector<int> v(span.getVect());
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			os << *it << "   ";
		}
	}
	return (os);
}

unsigned int Span::getSize(void) const { return (this->_size); }

const std::vector<int> & Span::getVect(void) const { return (this->_vect); }

void Span::addNumber(int number) {
	if (this->_vect.size() >= this->_size) {
		return (throw SpanOverflowException());
	}
	this->_vect.push_back(number);
}

void Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) > this->_size) {
		throw SpanOverflowException();
	}
	this->_vect.insert(this->_vect.end(), begin, end);
}

int Span::shortestSpan(void) const {
	if (this->_vect.size() < 2) {
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
	if (this->_vect.size() < 2) {
		throw NotEnoughNumbersException();
	}
	return (*std::max_element(this->_vect.begin(), this->_vect.end()) - *std::min_element(this->_vect.begin(), this->_vect.end()));
}

const char* Span::SpanOverflowException::what() const throw() {
	return ("Error: span is already full");
}

const char* Span::NotEnoughNumbersException::what() const throw() {
	return ("Error: not enough numbers to get span");
}
