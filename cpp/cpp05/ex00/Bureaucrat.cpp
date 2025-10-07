#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    if (_grade < MAX_GRADE) {
        throw GradeTooHighException();
    }
    if (_grade > MIN_GRADE) {
        throw GradeTooLowException();
    }
    std::cout << "Bureaucrat " << _name << ", with the grade " << _grade << " has been created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade(){
    if (_grade-- < MAX_GRADE)
        throw GradeTooHighException();
    else
        std::cout << "Bureaucrat " << _name << "'s grade has been incremented to " << _grade << std::endl;
}

void Bureaucrat::decrementGrade(){
    if (_grade++ > MIN_GRADE)
        throw GradeTooLowException();
    else
        std::cout << "Bureaucrat " << _name << "'s grade has been decremented to " << _grade << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur) {
    os << "Grade is: " << bur.getGrade() << ", Name is: " << bur.getName() << ". ";
    return os;
}