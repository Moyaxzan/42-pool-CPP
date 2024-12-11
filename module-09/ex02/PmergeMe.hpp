#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <exception>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <list>

template<typename Iterator>
class PmergeMe {
	public:
		// typedefs for clarity
		typedef std::random_access_iterator_tag iterator_category;
		typedef Iterator iterator_type;
		typedef typename std::iterator_traits<Iterator>::value_type value_type;
		typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename std::iterator_traits<Iterator>::pointer pointer;
		typedef typename std::iterator_traits<Iterator>::reference reference;
		// constructors and canonical form
		PmergeMe(void): baseIt_(), size_(0) {}
		PmergeMe(Iterator it, size_t size): baseIt_(it), size_(size) {}
		PmergeMe(const PmergeMe& other): baseIt_(other.baseIt_), size_(other.size_) {}
		PmergeMe& operator=(const PmergeMe& other) {
			this->size_ = other.size_;
			this->baseIt_ = other.baseIt_;
			return (*this);
		}
		~PmergeMe(void) {}

		// getters/setters
		Iterator getBase(void) const { return (this->baseIt_); }
		size_t getSize(void) const { return (this->size_); }

		// accessors operators 
		reference operator*(void) const { return (this->baseIt_[this->size_ - 1]); }
		pointer operator->(void) const { return (&operator*()); }
		reference operator[](std::size_t pos) { return (this->baseIt_[pos * size_ + size_ - 1]); }

		// operation operators
		PmergeMe& operator++(void) {
			this->baseIt_ += this->size_;
			return (*this);
		}
	
		PmergeMe operator++(int) {
			PmergeMe tmp = *this;
			++(*this);
			return (tmp);
		}

		PmergeMe& operator--(void) {
			this->baseIt_ -= this->size_;
			return (*this);
		}

		PmergeMe operator--(int) {
			PmergeMe tmp = *this;
			--(*this);
			return (tmp);
		}

		PmergeMe& operator+=(size_t increment) {
			this->baseIt_ += increment * this->size_;
			return (*this);
		}

		PmergeMe& operator-=(size_t decrement) {
			this->baseIt_ -= decrement * this->size_;
			return (*this);
		}

	private:
		Iterator baseIt_;
		size_t size_;
};

class InvalidInputException : public std::exception {
	public :
		const char * what(void) const throw();
};

template<typename RandomAccessIterator>
void mergeInsertion(RandomAccessIterator first, RandomAccessIterator last);
#endif
