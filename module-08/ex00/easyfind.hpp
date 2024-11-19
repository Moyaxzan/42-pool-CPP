#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <stdexcept>

template<typename T>
int easyfind(T container, int to_find) {
	typename T::iterator found;
	found = std::find(container.begin(), container.end(), to_find);
	if (found != container.end()) {
		return (*found);
	}
	throw std::runtime_error("value not found in container");
}

#endif
