#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string name, std::string target) {
    const std::string formNames[3] = { 
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (*formCreators[3])(std::string target) = {
        [](std::string target) -> AForm* { return new ShrubberyCreationForm(target); },
        [](std::string target) -> AForm* { return new RobotomyRequestForm(target); },
        [](std::string target) -> AForm* { return new PresidentialPardonForm(target); }
    };
    for (int i = 0; i < 3; ++i) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return formCreators[i](target);
        }
    }
    throw FormNotFound();
}