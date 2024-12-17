#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <exception>
#include <vector>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#ifndef DEBUG
# define DEBUG 0
#endif


template <typename Container>
class PmergeMe {
	public:
		// typedefs for clarity
		typedef typename Container::iterator vecIt;
		typedef typename std::vector<std::pair<typename Container::value_type, typename Container::value_type> >::iterator pairvecIt;

		// CANNONICAL FORM
		PmergeMe(void):
			container_(0),
			size_(0) {
		}

		PmergeMe(Container& container):
			container_(container),
			size_(container.size()) {
		}

		PmergeMe<Container>& operator=(PmergeMe& other) {
			if (&other != this) {
				this->container_ = other.container_;
				this->size_ = this->container_.size();
			}
			return (*this);
		}

		~PmergeMe<Container>(void) {
		}

		// GETTERS / SETTERS

		Container getContainer(void) const {
			return (this->container_);
		}

		void setContainer(Container& container) {
			this->container_ = container;
		}

		std::size_t getSize(void) const {
			return (this->size_);
		}

		// MEMBER FUNCTIONS

		Container mergeInsertSort(void) {
			std::vector<std::pair<int, int> > pairVect;
			Container mainChain;
			Container pendingChain;


			pairVect.reserve(this->size_ / 2);
			// mainChain.reserve(this->size_);
			// pendingChain.reserve(this->size_ / 2);

			// create pairs {littleValue, bigValue}
			for (unsigned long i = 0; i < this->size_ - 1; i += 2) {
				if (this->container_[i] > this->container_[i + 1]) {
					pairVect.push_back(std::make_pair(this->container_[i + 1], this->container_[i]));
				} else {
					pairVect.push_back(std::make_pair(this->container_[i], this->container_[i + 1]));
				}
			}

			// storing last element
			int pendingValue = -1;
			if (this->size_ % 2) {
				pendingValue = this->container_[this->size_ - 1];
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
			}
			// adding small values to the pending chain && large values to mainChain
			for (pairvecIt it = pairVect.begin(); it != pairVect.end(); it++) {
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
			this->jacobsthalInsertion(mainChain, pendingChain, pairVect);
			if (DEBUG) {
				std::cout << "mainChain :" << std::endl << "\t[";
				for (vecIt it = mainChain.begin(); it != mainChain.end(); it++) {
					std::cout << *it << ", ";
				}
				std::cout << "]" << std::endl;
			}
			return (mainChain);
		}

		void pairMerge(std::vector<std::pair<typename Container::value_type, typename Container::value_type> >& pairVect) {
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

		void jacobsthalInsertion(
						Container& mainChain, 
						Container& pendingChain, 
						std::vector<std::pair<typename Container::value_type, typename Container::value_type> > pairVect) {
			std::size_t pendingSize = pendingChain.size();
			unsigned long jacobsthal[] ={1,3,5,11,21,43,85,171,341,683,1365,2731,5461,10923,21845,43691,87381};
			std::size_t idx = 1;
			size_t t = 1;

			if (pendingSize % 2) {
				pendingSize--;
			}
			for (; jacobsthal[t] <= pendingSize; t++) {
				for (idx = jacobsthal[t] - 1; idx >= jacobsthal[t - 1]; idx--) {
					std::size_t upBound = std::lower_bound(mainChain.begin(), mainChain.end(), pairVect[idx].second) - mainChain.begin();
					typename Container::iterator insertPos = mainChain.begin() + vectBinarySearch(mainChain, pendingChain[idx], 0, upBound);
					mainChain.insert(insertPos, pendingChain[idx]);
					if (DEBUG)
						std::cout << "inserting " << pendingChain[idx] << " at " << insertPos - mainChain.begin() << std::endl;
				}
			}
			if (pendingChain.size() % 2) {
				pendingSize++;
			}
			idx = jacobsthal[t - 1];
			if (pendingSize > pairVect.size() && pendingSize > idx) {
				std::size_t upBound = mainChain.size() - 1;
				typename Container::iterator insertPos = mainChain.begin() + vectBinarySearch(mainChain, pendingChain[pendingSize - 1], 0, upBound);
				mainChain.insert(insertPos, pendingChain[pendingSize - 1]);
				if (DEBUG)
					std::cout << "inserting post " << pendingChain[pendingSize - 1] << " at " << insertPos - mainChain.begin() << std::endl;
				pendingSize--;
			}
			for (; pendingSize > idx; pendingSize--) {
				std::size_t upBound = std::lower_bound(mainChain.begin(), mainChain.end(), pairVect[pendingSize - 1].second) - mainChain.begin();
				typename Container::iterator insertPos = mainChain.begin() + vectBinarySearch(mainChain, pendingChain[pendingSize - 1], 0, upBound);
				mainChain.insert(insertPos, pendingChain[pendingSize - 1]);
				if (DEBUG)
					std::cout << "inserting post" << pendingChain[pendingSize - 1] << " at " << insertPos - mainChain.begin() << std::endl;
			}
		}


		int vectBinarySearch(const Container& container, 
							 typename Container::value_type value, 
							 int lowBound, int upBound) {
			// stop condition
			if (lowBound >= upBound) {
				if (value > container[lowBound]) {
					return (lowBound + 1);
				}
				return (lowBound);
			}
			int middle = (lowBound + upBound) / 2;
			if (value == container[middle]) {
				return (middle + 1);
			}
			if (value > container[middle]) {
				return (this->vectBinarySearch(container, value, middle + 1, upBound)); // recursive call
			}
			return (this->vectBinarySearch(container, value, lowBound, middle - 1)); // recursive call
		}

	private:
		Container container_;
		std::size_t size_;
};

// TODO : exception when more than 100000 values ?

class InvalidInputException : public std::exception {
	public :
		const char * what(void) const throw();
};

#endif
