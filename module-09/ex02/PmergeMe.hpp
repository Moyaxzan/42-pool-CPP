#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <exception>
#include <vector>
#include <deque>

class PmergeMe {
	public:
		static std::vector<int> vectMergeInsert(std::vector<int> vect);
		static std::deque<int> dequeMergeInsert(std::deque<int> deq);

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		// vect sort
		static void vectDividePairs_(
			std::vector<int>& baseVect,
			std::vector<int>& largerGroup,
			std::vector<int>& smallerGroup
		);
		static void vectInsertionSort_(std::vector<int>& sortedVect, std::vector<int> otherVect);
		static int vectBinarySearch_(std::vector<int> vect, int value, int lowBound, int upBound);

		// deque sort
		static void dequeDividePairs_(
			std::deque<int>& baseDeque,
			std::deque<int>& largerGroup,
			std::deque<int>& smallerGroup
		);
		static void dequeInsertionSort_(std::deque<int>& sortedDeque, std::deque<int> otherDeque);
		static int dequeBinarySearch_(std::deque<int> deq, int value, int lowBound, int upBound);
};

class InvalidInputException : public std::exception {
	public :
		const char * what(void) const throw();
};

#endif
