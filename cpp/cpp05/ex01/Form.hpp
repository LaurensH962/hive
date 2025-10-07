#pragma once

#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        bool _formSigned;
        const int _signGrade;
        const int _executeGrade;
    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const noexcept override {
                    return ("Form grade is slightly high don't you think?");
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const noexcept override {
                    return ("Form grade is quite a bit too low!");
                }
        };
        Form(std::string name, int signGrade, int executeGrade);
        Form(const Form& other);
        Form& operator=(const Form& other) = delete;
        ~Form();
        std::string getName() const;
        bool getSignature() const;
        void beSigned(const Bureaucrat& bur);
        int getExecute() const {}
        int getSignGrade() const {}

};

std::ostream& operator<<(std::ostream& os, const Form& bur);
