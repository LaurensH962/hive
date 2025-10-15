#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other._name, other._signGrade, other._executeGrade), _target(other._target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

std::string PresidentialPardonForm::getTarget() const { return _target; }

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > _executeGrade || !_formSigned)
        throw CannotExecute();
    std::cout << "Target: " << _target << " has been pardoned by Zaphod Beeblebrox! ♕" << std::endl;
}