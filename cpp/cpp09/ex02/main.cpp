#include "PmergeMe.hpp"
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Error: Invalid usage, try ./PmergeMe <numbers> " << std::endl;
        return 1;
    }
    std::vector<int> vec;
    for (int i = 1; i < argc; i++) {
        vec.push_back(std::atoi(argv[i]));
    }
    PmergeMe::sortVector(vec);
    // for (int n: vec)
    //     std::cout << n << ' ';
    // std::cout << std::endl;
}