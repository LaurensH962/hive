#include "PmergeMe.hpp"
#include <cstdlib>
#include <algorithm>
#include <chrono>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Invalid usage, try ./PmergeMe <numbers> " << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        for (size_t k = 0; k < arg.length(); k++) {
            if (!std::isdigit(static_cast<unsigned char>(arg[k]))) {
                std::cerr << "Error: Invalid input: " << arg << std::endl;
                return 1;
            }
        }
    }

    std::vector<int> validate;
    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; i++) {
        validate.push_back(std::atoi(argv[i]));
        vec.push_back(std::atoi(argv[i]));
        deq.push_back(std::atoi(argv[i]));
    }

    std::sort(validate.begin(), validate.end());
    for(size_t i = 0; i < validate.size() - 1; i++) {
        if (validate[i] == validate[i + 1]) {
            std::cerr << "Error: Double number: " << validate[i] << std::endl;
            return 1;
        }
    }
    
    std::cout << "Before: ";
    print_vec(vec);

    if (std::is_sorted(vec.begin(), vec.end())) {
        // std::cout <<"COMPARISON COUNT: " << comparison_count << std::endl;
        std::cout << "Vector is aleady sorted" << std::endl;
        return 0;
    }
    auto t1 = std::chrono::steady_clock::now();
    PmergeMe::sortVector(vec);
    auto t2 = std::chrono::steady_clock::now();
    if (!std::is_sorted(vec.begin(), vec.end())) {
        std::cout << "SORTING FAILED" << std::endl;
        return 0;
    }
    std::chrono::duration<double, std::milli> ms_double_v = t2 - t1;
    std::cout << "After: ";
    print_vec(vec);


    auto t3 = std::chrono::steady_clock::now();
    PmergeMe::sortDeque(deq);
    auto t4 = std::chrono::steady_clock::now();
    if (!std::is_sorted(deq.begin(), deq.end())) {
        std::cout << "SORTING FAILED" << std::endl;
        return 0;
    }
    std::chrono::duration<double, std::milli> ms_double_d = t4 - t3;
    std::cout << "Time to process a range of " << vec.size() << " elements with a vector: " << ms_double_v.count() << " ms\n";
    std::cout << "Time to process a range of " << vec.size() << " elements with a deque: " << ms_double_d.count() << " ms\n";
    // std::cout <<"COMPARISON COUNT: " << comparison_count << std::endl;  
}
