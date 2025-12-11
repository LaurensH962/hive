#pragma once
#include <vector>
#include <deque>
#include <iostream>

struct Chunk { 
	std::vector<int> numbers; 
	size_t id; 
};


class PmergeMe {
	public:
		PmergeMe() = delete;
		PmergeMe(const PmergeMe &other) = delete;
		PmergeMe &operator=(const PmergeMe &other) = delete;
		~PmergeMe() = default;

		static void sortVector(std::vector<int> &vec);
		// static void sortDeque(std::deque<int> &deq);
};