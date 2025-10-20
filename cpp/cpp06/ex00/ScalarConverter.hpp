#pragma once

#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>

enum class InputType {
    Char,
    Int,
    Float,
    Double,
    Invalid
};

class ScalarConverter {
    private:
    public:
        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter& other) = delete;
        ScalarConverter& operator=(const ScalarConverter& other) = delete;
        ~ScalarConverter() = delete;
        static void convert(std::string input);
};