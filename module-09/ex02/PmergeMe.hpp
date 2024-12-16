#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <exception>
#include <vector>
#ifndef DEBUG
# define DEBUG 0
#endif


class vectMergeInsert {
	public:
		// typedef for clarity
		typedef std::vector<std::pair<int, int> >::iterator pairvecIt;
		typedef std::vector<int>::iterator vecIt;

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
		void jacobsthalInsertion(	std::vector<int>& mainChain,
									std::vector<int>& pendingChain,
									std::vector<std::pair<int, int> > pairVect);

	private:
		std::vector<int> vect_;
		std::size_t size_;
};

// TODO : exception when more than 100000 values ?

class InvalidInputException : public std::exception {
	public :
		const char * what(void) const throw();
};

#endif
