#pragma once

#include <cstdint>
#include <iostream>

struct Data {
    std::string hello = "hello";
};

class Serializer{
    private:
        Serializer() = delete;
        Serializer(const Serializer& other) = delete;
        Serializer& operator=(const Serializer& other) = delete;
        ~Serializer() = delete;
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};