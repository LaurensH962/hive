#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat bur1("fred", 10);
        Bureaucrat bur2("frederike", 1000);
        std::cout << bur1 << bur2 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }

    try {
        Bureaucrat bur1("carl", 100);
        Bureaucrat bur2("carlotta", 0);
        std::cout << bur1 << bur2 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }

    try {
        Bureaucrat bur1("toni", 1);
        Bureaucrat bur2("tanja", -1);
        std::cout << bur1 << bur2 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }

    try {
        Bureaucrat bur1("patrik", 1);
        Bureaucrat bur2("patricia", 150);
        std::cout << bur1 << bur2 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    
    return 0;
}