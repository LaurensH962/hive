#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    if (_grade < MAX_GRADE) {
        throw GradeTooHighException();
    }
    if (_grade > MIN_GRADE) {
        throw GradeTooLowException();
    }
    std::cout << "a bureaucrat has been born" << std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade(){
    _grade--;
    if (_grade < MAX_GRADE)
        throw GradeTooHighException();
    else
        std::cout << "Bureaucrat " << _name << "'s grade has been incremented to " << _grade << std::endl;
}

void Bureaucrat::decrementGrade(){
    _grade++;
    if (_grade > MIN_GRADE)
        throw GradeTooLowException();
    else
        std::cout << "Bureaucrat " << _name << "'s grade has been decremented to " << _grade << std::endl;
}

void Bureaucrat::signForm(AForm& form, const Bureaucrat& bur) {
    form.beSigned(bur);
    if (form.getSignature())
        std::cout << _name<< " signed " << form.getName() << std::endl; 
    else
        std::cout << _name << " cannot sign " << form.getName() << ", because grade is not high enough " << std::endl; 
}

void Bureaucrat::executeForm(AForm const & form) const {
	form.execute(*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur) {
    os << "BUREAUCRAT: name is: " << bur.getName() << ", grade is: " << bur.getGrade() << ". ";
    return os;
}