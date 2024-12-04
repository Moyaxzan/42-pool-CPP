#include "PmergeMe.hpp"
#include <vector>

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void) other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void) other;
	return (*this);
}

PmergeMe::~PmergeMe(void) {}

std::vector<int> PmergeMe::vectMergeInsert(std::vector<int> vect) {
	if (vect.size() == 1) { // stop condition
		return (vect);
	}
	std::vector<int> res;
	if (vect.size() == 2) {
		if (vect[0] <= vect[1]) {
			res = vect;
		} else {
			res.push_back(vect[1]);
			res.push_back(vect[0]);
		}
		return (res);
	}
	std::vector<int> largerGroup;
	std::vector<int> smallerGroup;
	vectDividePairs_(vect, largerGroup, smallerGroup);
	res = PmergeMe::vectMergeInsert(largerGroup); // recursive call
	PmergeMe::vectInsertionSort_(res, smallerGroup);
	return (res);
}

void PmergeMe::vectInsertionSort_(std::vector<int> &sortedVect, std::vector<int> otherVect) {
	for (std::vector<int>::iterator it = otherVect.begin(); it != otherVect.end(); it++) { 
		std::vector<int>::iterator pos = sortedVect.begin() + vectBinarySearch_(sortedVect, *it, 0, sortedVect.size() - 1);
		sortedVect.insert(pos, *it);
	}
}

int PmergeMe::vectBinarySearch_(std::vector<int> vect, int value, int lowBound, int upBound) {
	// stop condition
	if (lowBound >= upBound) {
		if (value > vect[lowBound]) {
			return (lowBound + 1);
		}
		return (lowBound);
	}
	int middle = (lowBound + upBound) / 2;
	if (value == vect[middle]) {
		return (middle + 1);
	}
	if (value > vect[middle]) {
		return (PmergeMe::vectBinarySearch_(vect, value, middle + 1, upBound)); // recursive call
	}
	return (PmergeMe::vectBinarySearch_(vect, value, lowBound, middle - 1)); // recursive call
}

void PmergeMe::vectDividePairs_(
	std::vector<int>& baseVect,
	std::vector<int>& largerGroup,
	std::vector<int>& smallerGroup
) {
	for (std::vector<int>::iterator it = baseVect.begin(); it != baseVect.end(); it++) {
		int first = *it;
		it++;
		if (it == baseVect.end()) {
			smallerGroup.push_back(first);
			break;
		}
		int second = *it;
		largerGroup.push_back(max_(first, second));
		smallerGroup.push_back(min_(first, second));
	}
}

int PmergeMe::max_(int a, int b) {
	if (a > b) {
		return (a);
	}
	return (b);
}

int PmergeMe::min_(int a, int b) {
	if (a < b) {
		return (a);
	}
	return (b);
}

// std::vector<int> PmergeMe::dequeMergeInsert(std::vector<int> vect) {
//
// }

const char * InvalidInputException::what(void) const throw() {
	return ("Error");
}
