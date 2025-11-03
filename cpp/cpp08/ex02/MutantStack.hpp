#pragma once
#include <stack> 
#include <deque> 


template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
    public:
        using std::stack<T, Container>::c;
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;

        iterator begin(){ return c.begin();};
        iterator end(){ return c.end();};
        const_iterator begin() const { return c.begin();};
        const_iterator end() const { return c.end();};
};