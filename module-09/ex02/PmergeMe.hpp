#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <exception>
#include <vector>
#ifndef DEBUG
# define DEBUG 0
#endif

class vectMergeInsert {
	public:
		// canonical form
		vectMergeInsert(void);
		vectMergeInsert(std::vector<int> &vect);
		vectMergeInsert& operator=(vectMergeInsert& other);
		~vectMergeInsert(void);

		// getters/setters
		std::vector<int> getVect(void) const;
		void setVect(std::vector<int>& vect);
		std::size_t getSize(void) const;

		// member functions
		std::vector<int> mergeInsertSort(void); // TODO
		void pairMerge(std::vector<std::pair<int, int> >& pairVect);


	private:
		std::vector<int> vect_;
		std::size_t size_;
};

class InvalidInputException : public std::exception {
	public :
		const char * what(void) const throw();
};

#endif
