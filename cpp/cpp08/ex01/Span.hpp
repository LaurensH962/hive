#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
    private:
        unsigned int _max;
        std::vector<int> _values;
    public:
        Span() = delete;
        Span(unsigned int n);
        Span(const Span& other) = delete;
        Span& operator=(const Span& other)= delete;
        ~Span();
        void addNumber(const unsigned int& n);
        int shortestSpan();
        int longestSpan();
};
