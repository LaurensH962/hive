#include "PhoneBook.hpp"

int main(void)
{
    std::cout << "You opened a PhoneBook. what do you want to do?" << std::endl;
    displayStartPrompt();
    std::string input;
    PhoneBook phone_book;
    while (1)
    {
        safeGetline(input);
        if (input == "ADD")
            phone_book.addContact();
        else if (input == "SEARCH")
            phone_book.searchContacts(); 
        else if (input == "EXIT")
            break;
        else
        {
            std::cout << "No valid input. Try 'ADD', 'SEARCH' or 'EXIT' \n" << std::endl;
            continue;
        }
        displayStartPrompt();
    }
    std::cout << "You closed the phone book\n";
    return (0);
}