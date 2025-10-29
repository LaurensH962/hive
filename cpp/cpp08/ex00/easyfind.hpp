#pragma once

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& para1, int value){
    auto it = std::find(para1.begin(), para1.end(), value);
    if (it == para1.end())
        throw std::runtime_error("Value not found in container");
    return it;
}