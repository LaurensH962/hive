#pragma once

#include <iostream>
#include <exception>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat;

class AForm {
    protected:
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
        class CannotExecute : public std::exception {
            public:
                const char* what() const noexcept override {
                    return ("This Form is invalid and will not be executed");
                }
        };
        AForm(std::string name, int signGrade, int executeGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other) = delete;
        virtual ~AForm();
        std::string getName() const;
        bool getSignature() const;
        void beSigned(const Bureaucrat& bur);
        int getExecute() const;
        int getSignGrade() const;
        virtual void execute(Bureaucrat const& executor) const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& bur);
