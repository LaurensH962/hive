#include "phonebook.hpp"

void    PhoneBook::add_contact()
{
    Contact new_contact;
    std::string input;
    std::cout << "First Name: ";
    safe_getline(input);
    new_contact.set_first_name(input);
    std::cout << "Last Name: ";
    safe_getline(input);
    new_contact.set_last_name(input);
    std::cout << "Nickname: ";
    safe_getline(input);
    new_contact.set_nick_name(input);
    std::cout << "Phone Number: ";
    safe_getline(input);
    new_contact.set_phone_number(input);
    std::cout << "Share your darkest secret with me 😈:";
    safe_getline(input);
    new_contact.set_darkest_secret(input);
    m_contacts[m_next_index] = new_contact;
    m_next_index = (m_next_index + 1) % 8;
    if (m_contact_count < 8)
        m_contact_count ++;
}

void    PhoneBook::display_contact(int index) const
{
    const Contact &c = m_contacts[index];
    std::cout << "|";
    std::cout << std::setw(10) << std::right << index << "|";
    std::cout << std::setw(10) << std::right << truncate(c.get_first_name(), 10) << "|";
    std::cout << std::setw(10) << std::right << truncate(c.get_last_name(), 10) << "|";
    std::cout << std::setw(10) << std::right << truncate(c.get_nick_name(), 10) << "|"  << std::endl;
    std::cout << "—————————————————————————————————————————————" << std::endl;

}

void    PhoneBook::display_information(int index) const
{
    const Contact &c = m_contacts[index];
    std::cout << c.get_first_name() << std::endl;
    std::cout << c.get_last_name() << std::endl;
    std::cout << c.get_nick_name() << std::endl;
    std::cout << c.get_phone_number() << std::endl;
    std::cout << c.get_darkest_secret() << std::endl;
}

void    PhoneBook::search_contacts() const
{
    std::cout << "—————————————————————————————————————————————" << std::endl;
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    std::cout << "—————————————————————————————————————————————" << std::endl;

    for (int i = 0; i < m_contact_count; i++)
        display_contact(i);
    std::cout << "Display contact information by typing index number." << std::endl;
    std::string input;
    safe_getline(input);
    try
    {
        int num = std::stoi(input);
        if (num > m_contact_count - 1)
        {
             std::cout << "Contact does not exist." << std::endl;
             return;
        }
        if (num >= 0 && num <=7)
            display_information(num);
    }
    catch (const std::invalid_argument&) 
    {
        std::cout << "Not a number.\n";
        return;
    }
    catch (const std::out_of_range&) 
    {
        std::cout << "Number is too large or too small.\n";
        return;
    }
}