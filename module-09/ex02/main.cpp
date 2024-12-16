/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:56:00 by tsaint-p          #+#    #+#             */
/*   Updated: 2024/12/16 14:39:52 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <bits/types/struct_timeval.h>
#include <cctype>
#include <deque>
#include <exception>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <sys/time.h>

std::vector<int> get_vect(int argc, char *argv[]) {
	std::vector<int> res;
	int val;
	for (int i = 1; i < argc; i++) {
		std::string str(argv[i]);
		for (std::string::iterator it = str.begin(); it != str.end(); it++) {
			if (!std::isdigit(*it) && (*it != '+' || it != str.begin())) {
				throw (InvalidInputException());
			}
		}
		std::istringstream iss(str);
		iss >> val;
		if (iss.fail() || val < 0) {
			throw (InvalidInputException());
		} 
		res.push_back(val);
	}
	return (res);
}

std::deque<int> get_deque(int argc, char* argv[]) {
	std::deque<int> res;
	int val;
	for (int i = 1; i < argc; i++) {
		std::string str(argv[i]);
		std::istringstream iss(str);
		iss >> val;
		res.push_back(val);
	}
	return (res);
}

// print vect
std::ostream& operator<<(std::ostream& os, const std::vector<int>& vect) {
	for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); it++) {
		std::cout << *it << " ";
	}
	return (os);
}

// print deque
std::ostream& operator<<(std::ostream& os, const std::deque<int>& deq) {
	for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++) {
		std::cout << *it << " ";
	}
	return (os);
}

int main(int argc, char *argv[]) {
	try {
		std::vector<int> base_vect = get_vect(argc, argv);
		std::cout << "Before: " << base_vect << std::endl;
		// timeval start, end;
		// gettimeofday(&start, NULL);
		// sort vect
		vectMergeInsert vmi(base_vect);
		vmi.mergeInsertSort();
		// gettimeofday(&end, NULL);
		// std::cout << "After: " << base_vect << std::endl;
		// std::cout << "Time to process a range of " << base_vect.size();
		// std::cout << " elements with std::vect : "<< end.tv_usec - start.tv_usec << " us" << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
