#include <vector>
#include <set>
#include <iostream>
#include "easyfind.hpp"

int main() {
    std::vector<int> v = {1, 2 , 3, 4, 5};
    //VALID
    try
    {
        auto it = easyfind(v, 3);
        std::cout << "3rd value in container is:" << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //OUT OF BOUNDS
    try
    {
        auto it = easyfind(v, 23);
        std::cout << "3rd value in container is:" << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //SET
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