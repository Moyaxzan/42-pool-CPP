#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>
#include <cstddef>

template<typename T>
class Array {
	public:
		Array(void) : _array(new T[0]), _len(0) {
			if (!_array) {
				throw(MemoryFailException());
			}
		};

		Array(unsigned int n) : _array(new T[n]), _len(n) {
			if (!_array) {
				throw(MemoryFailException());
			}
			for (unsigned int i = 0; i < n; i++) {
				_array[i] = 42;
			}
		}

		Array(const Array& other) {
			if (&other != this) {
				if (other._array) {
					this->_len = other._len;
					for (unsigned int i = 0; i < this->_len; i++) {
						this->_array[i] = other._array[i];
					}
				} else {
					this->_array = NULL;
				}
			}
		}

		Array& operator=(const Array& other) {
			if (this != &other) {
				this->_len = other._len;
				if (this->_array) {
					delete [] this->_array;
				}
				this->_array = new T[this->_len];
				if (!this->_array) {
					throw MemoryFailException();
				}
				for (unsigned int i = 0; i < this->_len; i++) {
					this->_array[i] = other._array[i];
				}
			}
			return (*this);
		}

		~Array(void) {
			if (this->_array) {
				delete [] this->_array;
			}
		}

		T& operator[](const unsigned int i) {
			if (i >= this->_len) {
				throw IndexOutOfBoundsException();
			}
			return (this->_array[i]);
		}

		const T& operator[](const unsigned int i) const {
			if (i >= this->_len) {
				throw IndexOutOfBoundsException();
			}
			return (this->_array[i]);
		}

		unsigned int size(void) { return (this->_len); }

		class IndexOutOfBoundsException : public std::exception {
			public :
				const char* what(void) const throw() {
					return ("Error: index out of bounds");
				}
		};
		class MemoryFailException : public std::exception {
			public :
				const char* what(void) const throw() {
					return ("Error: couln't allocate memory");
				}
		};

	private:
		T* _array;
		unsigned int _len;
};

#endif
