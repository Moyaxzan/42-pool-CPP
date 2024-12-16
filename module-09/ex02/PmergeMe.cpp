#include "PmergeMe.hpp"
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

// CANNONICAL FORM

vectMergeInsert::vectMergeInsert(void):
	vect_(0),
	size_(0) {
}

vectMergeInsert::vectMergeInsert(std::vector<int> &vect):
	vect_(vect),
	size_(vect.size()) {
}

vectMergeInsert& vectMergeInsert::operator=(vectMergeInsert& other) {
	if (&other != this) {
		this->vect_ = other.vect_;
		this->size_ = this->vect_.size();
	}
	return (*this);
}

vectMergeInsert::~vectMergeInsert(void) {
}

// GETTERS / SETTERS

std::vector<int> vectMergeInsert::getVect(void) const {
	return (this->vect_);
}

void vectMergeInsert::setVect(std::vector<int>& vect) {
	this->vect_ = vect;
}

std::size_t vectMergeInsert::getSize(void) const {
	return (this->size_);
}

// MEMBER FUNCTIONS

std::vector<int> vectMergeInsert::mergeInsertSort(void) {
	std::vector<std::pair<int, int> > pairVect;
	std::vector<int> mainChain;
	std::vector<int> pendingChain;

	// create pairs {littleValue, bigValue}
	for (unsigned long i = 0; i < this->size_ - 1; i += 2) {
		if (this->vect_[i] > this->vect_[i + 1]) {
			pairVect.push_back(std::make_pair(this->vect_[i + 1], this->vect_[i]));
		} else {
			pairVect.push_back(std::make_pair(this->vect_[i], this->vect_[i + 1]));
		}
	}

	// storing last element
	int pendingValue = -1;
	if (this->size_ % 2) {
		pendingValue = this->vect_[this->size_ - 1];
	}

	// sorting pairs with their second values
	this->pairMerge(pairVect);

	if (DEBUG) {
		std::cout << "sorted pairs :" << std::endl << "\t";
		for (pairvecIt it = pairVect.begin(); it < pairVect.end(); it++) {
			std::cout << "{" << it->first << ", " << it->second << "} ";
		}
		std::cout << std::endl;
	}

	//adding value smaller than smallest large number to mainChain
	if (!pairVect.empty()) {
		mainChain.push_back(pairVect[0].first);
		mainChain.push_back(pairVect[0].second);
	}
	// adding small values to the pending chain && large values to mainChain
	for (pairvecIt it = pairVect.begin() + 1; it != pairVect.end(); it++) {
		pendingChain.push_back(it->first);
		mainChain.push_back(it->second);
	}
	// adding pending value to the end of pendingChain
	if (pendingValue != -1) {
		pendingChain.push_back(pendingValue);
	}

	if (DEBUG) {
		std::cout << "mainChain :" << std::endl << "\t[";
		for (vecIt it = mainChain.begin(); it != mainChain.end(); it++) {
			std::cout << *it << ", ";
		}
		std::cout << "]\npendingChain :" << std::endl << "\t[";
		for (vecIt it = pendingChain.begin(); it != pendingChain.end(); it++) {
			std::cout << *it << ", ";
		}
		std::cout << "]" << std::endl;
	}
	return (mainChain);
}

void vectMergeInsert::pairMerge(std::vector<std::pair<int, int> >& pairVect) {
	std::size_t vectSize = pairVect.size();
	// stop condition for recursive function
	if (vectSize < 2) {
		return ;
	}
	// splittin vect in 2 halves
	std::vector<std::pair<int, int> >::iterator midPoint = pairVect.begin() + (vectSize / 2);
	std::vector<std::pair<int, int> > leftPairs(pairVect.begin(), midPoint);
	std::vector<std::pair<int, int> > rightPairs(midPoint, pairVect.end());

	// recursive sort of the 2 halves
	this->pairMerge(leftPairs);
	this->pairMerge(rightPairs);

	// merging together left and right pairs
	
	std::size_t leftIdx = 0, rightIdx = 0, mergedIdx = 0;
	std::size_t leftSize = leftPairs.size(), rightSize = rightPairs.size();

	while (leftIdx < leftSize && rightIdx < rightSize) {
		if (leftPairs[leftIdx].second < rightPairs[rightIdx].second) {
			pairVect[mergedIdx] = leftPairs[leftIdx++];
		} else {
			pairVect[mergedIdx] = rightPairs[rightIdx++];
		}
		mergedIdx++;
	}
	while (leftIdx < leftSize) {
		pairVect[mergedIdx++] = leftPairs[leftIdx++];
	}
	while (rightIdx < rightSize) {
		pairVect[mergedIdx++] = rightPairs[rightIdx++];
	}
}

void vectMergeInsert::jacobsthalInsertion(
		std::vector<int>& mainChain,
		std::vector<int>& pendingChain,
		std::vector<std::pair<int, int> > pairVect) {
	std::size_t pendingSize = pendingChain.size();
	unsigned long jacobsthal[] ={2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846, 43690, 87382};


}
// EXCEPTIONS
const char* InvalidInputException::what(void) const throw() {
	return ("Error\n");
}
