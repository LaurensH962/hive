#include <iostream>

void to_upper(std::string &s) {
    for (size_t i = 0; i < s.length(); ++i) {
        s[i] = std::toupper(s[i]);
    }
}

int main(int argc, char **argv) {

    if (argc <= 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        to_upper(arg);
        std::cout << arg;
    }
    std::cout << std::endl;
    return (0);
}