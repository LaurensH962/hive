#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 2) {
        std::cout << "invalid usage. try ./scalarConverter <value>" << std::endl;
        return 0;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}