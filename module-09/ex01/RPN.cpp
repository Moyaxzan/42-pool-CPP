#include "RPN.hpp"
#include <cctype>
#include <exception>
#include <iostream>

RPN::RPN(void) {
}

RPN::RPN(const RPN& other) {
	this->stack_ = other.stack_;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->stack_ = other.stack_;
	}
	return (*this);
}

RPN::~RPN(void) {
}

void RPN::makeOperation(char c) {
	void (RPN::*operations[])() = {
		&RPN::applyAdd_,
		&RPN::applySubstract_,
		&RPN::applyMult_,
		&RPN::applyDivide_
	};
	if (getOperationNum_(c) != -1) {
		if (this->stack_.size() < 2) {
			throw (std::exception());
		}
		(this->*operations[getOperationNum_(c)])();
	} else {
		if (!std::isdigit(c)) {
			throw (std::exception());
		}
		this->stack_.push(c - '0');
	}
}

int RPN::getResult(void) const {
	if (this->stack_.size() > 1) {
		throw (std::exception());
	}
	return (this->stack_.top());
}

void RPN::applyAdd_(void) {
	this->stack_.push(this->betterPop_() + this->betterPop_());
}

void RPN::applySubstract_(void) {
	int r_elem = this->betterPop_();
	int l_elem = this->betterPop_();
	this->stack_.push(l_elem - r_elem);
}

void RPN::applyMult_(void) {
	this->stack_.push(this->betterPop_() * this->betterPop_());
}

void RPN::applyDivide_(void) {
	this->stack_.push(this->betterPop_() / this->betterPop_());
}

int RPN::betterPop_(void) {
	if (this->stack_.size() < 1) {
		throw (std::exception());
	}
	int res = this->stack_.top();
	this->stack_.pop();
	return (res);
}

int RPN::getOperationNum_(char c) const {
	if (c == '+') {
		return (0);
	} else if (c == '-') {
		return (1);
	} else if (c == '*') {
		return (2);
	} else if (c == '/') {
		return (3);
	} else {
		return (-1);
	}
}
