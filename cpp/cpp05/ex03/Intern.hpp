#pragma once

#include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern& other) = delete;
        Intern& operator=(const Intern& other) = delete;
        ~Intern();
        AForm* makeForm(std::string name, std::string target);
        class FormNotFound : public std::exception {
            public:
                const char* what() const noexcept override {
                    return ("Form not found");
                }
        };
};