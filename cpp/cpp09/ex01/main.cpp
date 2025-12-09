#include "RPN.hpp"
#include <iostream>


int main(int argc, char* argv[]) {
     if (argc != 2) {
        std::cerr << "Error: invalid usage. Try ./RPN <formula>" << std::endl;
        exit (1);
    }
    try {
        RPN rpn(argv[1]);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}