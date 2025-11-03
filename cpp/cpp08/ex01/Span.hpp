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
        template <typename InputIterator>
        void addNumber(InputIterator begin, InputIterator end){
            if (std::distance(begin, end) + _values.size() > _max)
                throw std::out_of_range("Adding this range would exceed Span capacity");
            _values.insert(_values.end(), begin, end);
        }
};
