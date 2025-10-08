#include "AForm.hpp"
#include "Bureaucrat.hpp" 

AForm::AForm(std::string name, int signGrade, int executeGrade, std::string target) :   _name(name),
                                                                                        _formSigned(false),
                                                                                        _signGrade(signGrade),
                                                                                        _executeGrade(executeGrade),
                                                                                        _target(target) {
     if (_signGrade < MAX_GRADE || _executeGrade < MAX_GRADE) {
        throw GradeTooHighException();
    }
    if (_signGrade > MIN_GRADE || _executeGrade > MIN_GRADE) {
        throw GradeTooLowException();
    }
    std::cout << "a form has been printed" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name),
                                _formSigned(other._formSigned),
                                _signGrade(other._signGrade),
                                _executeGrade(other._executeGrade) {}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }

bool AForm::getSignature() const { return _formSigned; }

int AForm::getExecute() const { return _executeGrade; }

int AForm::getSignGrade() const { return _formSigned; }

std::string AForm::getTarget() const { return _target; }

void AForm::beSigned(const Bureaucrat& bur) {
    if (bur.getGrade() <= _signGrade)
        _formSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "\nFORM: Name is: " << form.getName() << ", sign Grade is: " << form.getSignGrade() 
       << ", execution grade is: " << form.getExecute() << ", signature is: " << form.getSignature() 
       << " and the target is:" << form.getTarget() << ". ";
    return os;
}