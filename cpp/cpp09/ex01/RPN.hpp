#pragma once

#include <stack>
#include <iostream>

enum whatOperator{
    ADD,
    NEGATE,
    MULTIPLY,
    DIVIDE
};

class RPN {
    private:
        std::stack<long long> _rpn;
        int _operator;
    public:
        RPN()= default;
        RPN(std::string arg);
        RPN(const RPN& other) = default;
        RPN& operator=(const RPN& other) = default;
        ~RPN() = default;
        bool isValidOperator(int c);
};