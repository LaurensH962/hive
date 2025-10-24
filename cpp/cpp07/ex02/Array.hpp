#pragma once

template <typename T>
class Array {
    private:
        T* _data;
        size_t _size;
    public:
        Array();
        Array(const unsigned int& u);
        Array(const Array& other);
        Array& operator=(const Array& other);
        T& operator[](size_t index);
        size_t size() const;
        ~Array();
};

#include "Array.tpp"