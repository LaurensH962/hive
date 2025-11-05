#include "Iter.hpp"
#include <iostream>

template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

void increment(int& x) {
    x++;
}

int main() {
    std::cout << "== create array of numbers\n";
    int numbers[] = {1, 2, 3, 4, 5};
    std::size_t len = 5;
    std::cout << "Original numbers: ";
    iter(numbers, len, printElement<int>);
    std::cout << "\n";

    std::cout << "Incrementing numbers...\n";
    iter(numbers, len, increment);

    std::cout << "After increment: ";
    iter(numbers, len, printElement<int>);
    std::cout << "\n";

    std::cout << "== create array of strings\n";
    std::string names[] = {"Cauliflower", "Broccoli", "Cabbage"};
    std::cout << "Names: ";
    iter(names, 3, printElement<std::string>);

    return 0;
}