#include "Span.hpp"
#include <iostream>
#include <numeric> 

int main()
{
    std::cout << "\n=== test manual addNumber to span===\n";
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(6);
    sp.addNumber(18);
    sp.addNumber(3);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "\n=== test iterator span integration ===\n";
    std::vector<int> vec(10000);
    std::iota(vec.begin(), vec.end(), 0); 
    Span bigSpan(10000);
    bigSpan.addNumber(vec.begin(), vec.end());
    std::cout << bigSpan.shortestSpan() << std::endl;
    std::cout << bigSpan.longestSpan() << std::endl;
    return 0;
}