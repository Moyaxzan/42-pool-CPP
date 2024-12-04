#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <exception>
#include <vector>

class PmergeMe {
	public:
		static void vectMergeInsert(std::vector<int> vect);
		static void dequeMergeInsert(std::vector<int> vect);

	private:
		PmergeMe(void); // TODO
		PmergeMe(const PmergeMe& other); // TODO
		PmergeMe& operator=(const PmergeMe& other); // TODO
		~PmergeMe(); //TODO
};

class InvalidInputException : public std::exception {
	public :
		const char * what(void) const throw();
};

#endif
