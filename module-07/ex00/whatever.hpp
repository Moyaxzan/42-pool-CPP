#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T& p1, T& p2) {
	T tmp = p1;
	p1 = p2;
	p2 = tmp;
	return ;
}

template <typename T> T min(T &a, T &b) {
	if (a < b) {
		return (a);
	}
	return (b);
}

template <typename T> T max(T &a, T &b) {
	if (a > b) {
		return (a);
	}
	return (b);
}

#endif // !WHATEVER_HPP
