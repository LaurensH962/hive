#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        const std::string _target;
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = delete;
        ~PresidentialPardonForm() override;
        std::string getTarget() const;   
        void execute(Bureaucrat const& executor) const override;
        
};