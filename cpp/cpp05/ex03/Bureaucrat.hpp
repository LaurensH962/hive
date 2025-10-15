#pragma once

#include <iostream>
#include <exception>
#include "AForm.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat {
    private:
        const   std::string _name;
        int     _grade;
    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const noexcept override {
                    return ("Grade waaaaaaaaaay too high!");
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const noexcept override {
                    return ("Grade a bit too low!");
                }
        };
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other) = delete;
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm& form, const Bureaucrat& bur);
        void executeForm(AForm const & form) const ;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur);