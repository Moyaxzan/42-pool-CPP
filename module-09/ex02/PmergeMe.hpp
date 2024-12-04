#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <exception>
#include <vector>

class PmergeMe {
	public:
		static std::vector<int> vectMergeInsert(std::vector<int> vect);
		static std::vector<int> dequeMergeInsert(std::vector<int> vect);

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		static int max_(int a, int b);
		static int min_(int a, int b);

		static void vectDividePairs_(
			std::vector<int>& baseVect,
			std::vector<int>& largerGroup,
			std::vector<int>& smallerGroup
		);
		static void vectInsertionSort_(std::vector<int>& sortedVect, std::vector<int> otherVect);
		static int vectBinarySearch_(std::vector<int> vect, int value, int lowBound, int upBound);
};

class InvalidInputException : public std::exception {
	public :
		const char * what(void) const throw();
};

#endif
