#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <cstring>


template<typename Iterator>
typename PmergeMe<Iterator>::difference_type operator-(	const PmergeMe<Iterator>& lhs,
														const PmergeMe<Iterator>& rhs) {
	return (lhs.base() - rhs.base()) / lhs.size();
}

template<typename Iterator>
PmergeMe<Iterator> make_PmergeMe(Iterator it, size_t size) {
	return PmergeMe<Iterator>(it, size);
}

template<typename Iterator>
PmergeMe<Iterator> make_PmergeMe(PmergeMe<Iterator> it, size_t size) {
	return PmergeMe<Iterator>(it.getBase(), size * it.getSize());
}

template<typename Iterator>
void my_iter_swap(PmergeMe<Iterator> lhs, PmergeMe<Iterator> rhs) {
	size_t size = lhs.getSize();
    unsigned char temp[size];
    memcpy(temp, lhs, size);
    memcpy(lhs, rhs, size);
    memcpy(rhs, temp, size);
}

template<typename RandomAccessIterator>
void mergeInsertionSort(RandomAccessIterator first, RandomAccessIterator last) {
	static const unsigned long long jacobsthal_diff[] = {
		2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
		2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
		1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
		178956970, 357913942, 715827882, 1431655766, 2863311530, 5726623062,
		11453246122, 22906492246, 45812984490, 91625968982, 183251937962,
		366503875926, 733007751850, 1466015503702, 2932031007402, 5864062014806,
		11728124029610, 23456248059222, 46912496118442, 93824992236886, 187649984473770,
		375299968947542, 750599937895082, 1501199875790165, 3002399751580331,
		6004799503160661, 12009599006321322, 24019198012642644, 48038396025285288,
		96076792050570576, 192153584101141152, 384307168202282304, 768614336404564608,
		1537228672809129216ULL, 3074457345618258432ULL, 6148914691236516864ULL
	};

	size_t size = std::distance(first, last);
	if (size < 2) {
		return ;
	}
	bool isEven = !(size % 2);
	RandomAccessIterator end = last;
	if (!isEven) {
		end--;
	}

	// forming pairs + sorting couples
	for (RandomAccessIterator it = first; it != end; it += 2) {
		if (it[1] < it[0]) {
			my_iter_swap(it, it + 1);
		}
	}
	
	// recursive call with pairs
	mergeInsertionSort(make_PmergeMe(first, 2), make_PmergeMe(end, 2));

	// adding the 2 firsts values to mainchain
	std::list<RandomAccessIterator> mainChain;
	mainChain.push_back(first);
	mainChain.push_back(first + 1);

	std::vector<typename std::list<RandomAccessIterator>::iterator> pending;
	// add small values to pending
	for (RandomAccessIterator it = first + 2; it != end; it += 2) {
		pending.push_back(mainChain.insert(mainChain.end(), it + 1));
	}
	if (!isEven) {
		pending.push_back(mainChain.end());
	}


	//binary insertion
	RandomAccessIterator curr_it = first + 2;
	RandomAccessIterator curr_pend_it = pending.begin();
	RandomAccessIterator pend_it;
	RandomAccessIterator it;
	for (int k = 0; ; k++) {
		size_t dist = jacobsthal_diff[k];
		if (dist > static_cast<size_t>(std::distance(curr_pend_it, pending.end()))) {
			break;
		}
		it = curr_it + dist * 2;
		pend_it = curr_pend_it + dist;
	}
	do {
		pend_it -= 1;
		it  -= 2;
		std::upper_bound()
	} while (pend_it != curr_pend_it);
}
