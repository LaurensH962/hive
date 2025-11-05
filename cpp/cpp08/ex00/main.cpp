#include <vector>
#include <set>
#include <iostream>
#include "easyfind.hpp"

int main() {
    //VALID VECTOR
    std::vector<int> v = {1, 2 , 3, 4, 5};
    try
    {
        auto it = easyfind(v, 3);
        std::cout << "3rd value in container is:" << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //INVALID: OUT OF BOUNDS
    try
    {
        auto it = easyfind(v, 23);
        std::cout << "3rd value in container is:" << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //VALID SET
    std::set<int> s = {1, 2 , 3, 4, 5};
    try
    {
        auto it = easyfind(s, 2);
        std::cout << "3rd value in container is:" << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}