#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
    std::cout << "\n" << std::endl;

    AForm* rrf = nullptr;
    try {
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat bur("ROBOT CONNOISSEUR", 10);
        bur.signForm(*rrf, bur);
        bur.executeForm(*rrf);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    if (rrf != nullptr)
        delete rrf;

    std::cout << "\n" << std::endl;

    AForm* scf = nullptr;
    try{
        Intern uselessIntern;
        scf = uselessIntern.makeForm("shrubbery creation", "Brokkoli");
        Bureaucrat bur("PLANT PLANTER", 10);
        bur.signForm(*scf, bur);
        bur.executeForm(*scf);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    if (scf != nullptr)
        delete scf;
    
    std::cout << "\n" << std::endl;

    AForm* ppf = nullptr;
    try{
        Intern forgotTheNameIntern;
        ppf = forgotTheNameIntern.makeForm("presidential pardon", "Prisoner");
        Bureaucrat bur("PRISON GUARD", 10);
        bur.signForm(*ppf, bur);
        bur.executeForm(*ppf);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    if (ppf != nullptr)
        delete ppf;

    std::cout << "\n" << std::endl;

    AForm* notAvailable = nullptr;
    try{
        Intern firedTomorrowIntern;
        notAvailable = firedTomorrowIntern.makeForm("invalid form", "invalid target");
        Bureaucrat bur("RANDOM STUFF", 10);
        bur.signForm(*notAvailable, bur);
        bur.executeForm(*notAvailable);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    if (notAvailable != nullptr)
        delete notAvailable;

    return 0;
}