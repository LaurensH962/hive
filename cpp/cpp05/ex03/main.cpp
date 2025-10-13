#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
    std::cout << "\n" << std::endl;

    try {
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    Bureaucrat bur("ROBOT CONNOISSEUR", 10);
    bur.signForm(*rrf, bur);
    rrf->execute(bur);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }

    std::cout << "\n" << std::endl;

    try{
    Intern uselessIntern;
    AForm* scf;
    scf = uselessIntern.makeForm("shrubbery creation", "Brokkoli");
    Bureaucrat bur("PLANT PLANTER", 10);
    bur.signForm(*scf, bur);
    scf->execute(bur);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }
    
    std::cout << "\n" << std::endl;

    try{
    Intern forgotTheNameIntern;
    AForm* ppf;
    ppf = forgotTheNameIntern.makeForm("presidential pardon", "Prisoner");
    Bureaucrat bur("PRISON GUARD", 10);
    bur.signForm(*ppf, bur);
    ppf->execute(bur);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }

    std::cout << "\n" << std::endl;

    try{
    Intern firedTomorrowIntern;
    AForm* notAvailable;
    notAvailable = firedTomorrowIntern.makeForm("invalid form", "invalid target");
    Bureaucrat bur("RANDOM STUFF", 10);
    bur.signForm(*notAvailable, bur);
    notAvailable->execute(bur);
    }
    catch (std::exception& e) {
        std::cerr << "Exception error encountered: " << e.what() << "\n" << std::endl;
    }

    return 0;
}