#include "PhoneBook.hpp"

void    safeGetline(std::string &input)
{
    while (true)
    {
        if (!std::getline(std::cin, input))
        {
            if (std::cin.eof()) {
                std::cout << "\nEOF detected. closing phone book." << std::endl;
            } else {
                std::cout << "\nInput error. closing phone book." << std::endl;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            exit(1);
        }
        bool only_whitespace = true;
        for (char c : input) {
            if (!std::isspace(static_cast<unsigned char>(c))) {
                only_whitespace = false;
                break;
            }
        }
        if (!only_whitespace)
            break;
        std::cout << "Input cannot be empty. Please try again: ";
    }
}

std::string truncate(std::string str, size_t width)
{
    if (str.length() > width)
        return str.substr(0, width - 1) + ".";
    return str;
}

void    displayStartPrompt()
{
    std::cout << "\ntype 'ADD' to create new contact." << std::endl;
    std::cout << "type 'SEARCH' to search for existing contact." << std::endl;
    std::cout << "type 'EXIT' to close the PhoneBook.\n" << std::endl;
}