template <typename T>
Array<T>::Array() : _data(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(const unsigned int& u) : _data(new T[u]()), _size(u) {}

template <typename T>
Array<T>::Array(const Array& other) {
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == &other)
        return *this;
    T* newData = other._size ? new T[other._size] : nullptr;
    for (size_t i = 0; i < other._size; i++) {
        newData[i] = other._data[i];
    }
    delete[] _data;
    _data = newData;
    _size = other._size;
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= _size) 
        throw std::out_of_range("Index out of bounds");
    return _data[index];
}


template <typename T>
Array<T>::~Array() {
    delete[] _data;
}
