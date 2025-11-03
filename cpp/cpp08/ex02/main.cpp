#include "MutantStack.hpp"
#include <iostream>
#include <deque>

int main()
{
    /////
    std::cout << "=== TEST MutantStack ===\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);



    std::cout << "\n=== TEST with deque ===\n";
    std::deque<int> tDeque;
    tDeque.push_back(5);
    tDeque.push_back(17);
    std::cout << tDeque.back() << std::endl;
    tDeque.pop_back();
    std::cout << tDeque.size() << std::endl;
    tDeque.push_back(3);
    tDeque.push_back(5);
    tDeque.push_back(737);
    //[...]
    tDeque.push_back(0);
    std::deque<int>::iterator itDeque = tDeque.begin();
    std::deque<int>::iterator iteDeque = tDeque.end();
    ++itDeque;
    --itDeque;
    while (itDeque != iteDeque)
    {
        std::cout << *itDeque << std::endl;
        ++itDeque;
    }
    std::deque<int> sDeque(tDeque);

    return 0;
}