#include "Form.hpp"
#include "Bureaucrat.hpp" 

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name),
                                                                _formSigned(false),
                                                                _signGrade(signGrade),
                                                                _executeGrade(executeGrade) {
     if (_signGrade < MAX_GRADE || _executeGrade < MAX_GRADE) {
        throw GradeTooHighException();
    }
    if (_signGrade > MIN_GRADE || _executeGrade > MIN_GRADE) {
        throw GradeTooLowException();
    }
    std::cout << "a form has been printed" << std::endl;
}

Form::Form(const Form& other) : _name(other._name),
                                _formSigned(other._formSigned),
                                _signGrade(other._signGrade),
                                _executeGrade(other._executeGrade) {}

Form::~Form() {}

std::string Form::getName() const { return _name; }

bool Form::getSignature() const { return _formSigned; }

int Form::getExecute() const { return _executeGrade; }

int Form::getSignGrade() const { return _formSigned; }


void Form::beSigned(const Bureaucrat& bur) {
    if (bur.getGrade() <= _signGrade)
        _formSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "\nFORM: Name is: " << form.getName() << ", sign Grade is: " << form.getSignGrade() 
       << ", execution grade is: " << form.getExecute() << ", signature is: " << form.getSignature() << ". ";
    return os;
}