#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        const std::string _target;
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;
        ~ShrubberyCreationForm() override;
        std::string getTarget() const;   
        void execute(Bureaucrat const& executor) const override;
        
};