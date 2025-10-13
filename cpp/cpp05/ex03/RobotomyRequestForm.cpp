#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other._name, other._signGrade, other._executeGrade), _target(other._target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

std::string RobotomyRequestForm::getTarget() const { return _target; }

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > _executeGrade || !_formSigned)
        throw CannotExecute();

    std::cout << "BzzzzZzzzz... drilling noises... 🤖" << std::endl;

	srand(time(NULL));
    int willRobo = std::rand() % 2;
	std::cout << willRobo << std::endl;
    if (willRobo)
        std::cout << "Target: " << _target << " has been robotomized successfully! ✅" << std::endl;
    else
        std::cout << "Robotomization of " << _target << " failed. 😞" << std::endl;
}