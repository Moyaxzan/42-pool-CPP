#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <stdexcept>

template<typename T>
int easyfind(T container, int to_find) {
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it != container.end()) {
		return (*it);
	}
	throw std::runtime_error("value not found in container");
}

#endif
