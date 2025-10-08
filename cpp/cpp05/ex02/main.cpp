#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    try {
        Bureaucrat bur("A", 10);
        ShrubberyCreationForm shrub("home");
        bur.signForm(shrub, bur);
        shrub.execute(bur);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    try {
        Bureaucrat bur("B", 140);
        ShrubberyCreationForm toilet("toilet");
        bur.signForm(toilet, bur);
        toilet.execute(bur);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    try {
        Bureaucrat bur("C", 160);
        ShrubberyCreationForm toilet("roof");
        bur.signForm(toilet, bur);
        toilet.execute(bur);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    return 0;
}