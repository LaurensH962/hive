#include "RPN.hpp"

bool RPN::isValidOperator(int c){
    if (c == '+'){
        _operator = ADD;
        return true;
    }
    if (c == '-'){
        _operator = NEGATE;
        return true;
    }
    if (c == '*'){
        _operator = MULTIPLY;
        return true;
    }
    if (c == '/'){
        _operator = DIVIDE;
        return true;
    }
    return false;
}

RPN::RPN(std::string arg){
    for (size_t i = 0; i < arg.length(); i++){
        if (std::isspace(arg[i]))
            continue;
        else if (std::isdigit(arg[i])){
            _rpn.push(arg[i] - '0');
        }
        else if (isValidOperator(arg[i])) {
            if ( _rpn.size() < 2)
                throw std::runtime_error("invalid input");
            long long first = _rpn.top();
            _rpn.pop();
            long long second =_rpn.top();
            _rpn.pop();
            
            switch (_operator) {
                case ADD :
                    _rpn.push(second + first);
                    break;
                case NEGATE :
                    _rpn.push(second - first);
                    break;
                case MULTIPLY:
                    _rpn.push(second * first);
                    break;
                case DIVIDE :
                    if (first == 0)
                        throw std::runtime_error("no 0 division allowed");
                    _rpn.push(second / first);
                    break;
                default :
                    throw std::runtime_error("invalid input");
            }
        }
        else
            throw std::runtime_error("invalid character in formula");
    }
    if (_rpn.size() > 1)
        throw std::runtime_error("invalid input");
    std::cout << _rpn.top() << std::endl;
}