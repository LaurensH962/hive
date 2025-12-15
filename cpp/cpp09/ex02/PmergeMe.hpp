#pragma once
#include <vector>
#include <deque>
#include <iostream>

static int comparison_count = 0;

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
		static void sortDeque(std::deque<int> &deq);
};

void print_vec(std::vector<int>& vec);