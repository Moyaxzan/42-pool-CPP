#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <stdexcept>
#include <vector>

template <typename T>
typename T::value_type* easyfind(T& container, int to_find) {
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it != container.end()) {
		return (&(*it));
	}
	return (NULL);
}

#endif
