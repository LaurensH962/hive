#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        const std::string _target;
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;
        ~RobotomyRequestForm() override;
        std::string getTarget() const;   
        void execute(Bureaucrat const& executor) const override;
        
};