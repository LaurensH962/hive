#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
    std::cout << "TRY TO PLANT SHRUBBERY\n" << std::endl;
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
    std::cout << "\nEND OF PLANTING SHRUBBERY\n" << std::endl;



    std::cout << "TRY TO ROBO TIME\n" << std::endl;
    try {
        Bureaucrat bur("ROBO", 10);
        RobotomyRequestForm newRobo("biipbuuPbIIp");
        bur.signForm(newRobo, bur);
        newRobo.execute(bur);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    try {
        Bureaucrat bur("NoRobo", 140);
        RobotomyRequestForm notARobo("maybe Beep?");
        bur.signForm(notARobo, bur);
        notARobo.execute(bur);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    std::cout << "\nROBO OUT\n" << std::endl;


    std::cout << "YOU'VE BEEN FOUND GUILTY, WILL YOU BE PARDNED?\n" << std::endl;
    try {
        Bureaucrat bur("prisoner", 2);
        PresidentialPardonForm pris("pls let me live");
        bur.signForm(pris, bur);
        pris.execute(bur);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    try {
        Bureaucrat bur("prisoner2", 140);
        PresidentialPardonForm pris2("FUCK YOU Beeblebrox");
        bur.signForm(pris2, bur);
        pris2.execute(bur);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    std::cout << "\nSENTENCE CARRIED OUT\n" << std::endl;

    return 0;
}