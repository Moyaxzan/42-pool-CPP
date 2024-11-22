#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <cstddef>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
	public:
		MutantStack(void) {};
		MutantStack(MutantStack<T>& other) {};

		MutantStack<T>& operator=(MutantStack<T>& other) {
			if (*this != other) {
				this->c = other.c;
			}
			return (*this);
		};

		~MutantStack() {};

		
		typedef typename std::stack<int>::container_type::const_iterator const_iterator;
		typedef typename std::stack<int>::container_type::iterator iterator;
		
		iterator begin(void) {
			return (this->c.begin());
		}

		iterator end(void) {
			return (this->c.end());
		}

		const_iterator begin(void) const {
			return (this->c.begin());
		}

		const_iterator end(void) const {
			return (this->c.end());
		}
};

#endif
