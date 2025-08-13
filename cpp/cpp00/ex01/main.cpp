#include "phonebook.hpp"

int main(void)
{
    std::cout << "You opened a phonebook. what do you want to do?" << std::endl;
    display_start_prompt();
    std::string input;
    PhoneBook phone_book;
    while (1)
    {
        safe_getline(input);
        if (input == "ADD")
            phone_book.add_contact();
        else if (input == "SEARCH")
            phone_book.search_contacts(); 
        else if (input == "EXIT")
            break;
        else
        {
            std::cout << "No valid input. Try 'ADD', 'SEARCH' or 'EXIT' \n" << std::endl;
            continue;
        }
        display_start_prompt();
    }
    std::cout << "You closed the phone book\n";
    return (0);
}