#include "Span.hpp"

Span::Span(unsigned int n) : _max(n){}

Span::~Span(){}

void Span::addNumber(const unsigned int& n){
    if (_values.size() < _max) 
        _values.push_back(n);
    else {
        throw std::out_of_range("span alredy full, cannot add more numbers");
    }
}

int Span::shortestSpan(){
    if (_values.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");
    std::vector<int> temp = _values;
    std::sort(temp.begin(), temp.end());
    int minSpan = std::abs((temp[1] - temp[0]));
    for (size_t i = 1; i < temp.size() - 1; i++) {
        int span = std::abs(temp[i + 1] - temp[i]);
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan(){
    if (_values.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");
    auto it_min = min_element(_values.begin(), _values.end());
    auto it_max = max_element(_values.begin(), _values.end());
    int diff = std::abs(*it_min - *it_max);
    return diff;
}