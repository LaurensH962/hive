#include "PhoneBook.hpp"

void    PhoneBook::addContact()
{
    Contact new_contact;
    std::string input;
    std::cout << "First Name: ";
    safeGetline(input);
    new_contact.setFirstName(input);
    std::cout << "Last Name: ";
    safeGetline(input);
    new_contact.setLastName(input);
    std::cout << "Nickname: ";
    safeGetline(input);
    new_contact.setNickName(input);
    std::cout << "Phone Number: ";
    safeGetline(input);
    new_contact.setPhoneNumber(input);
    std::cout << "Share your darkest secret with me 😈:";
    safeGetline(input);
    new_contact.setDarkestSecret(input);
    m_contacts[m_next_index] = new_contact;
    m_next_index = (m_next_index + 1) % 8;
    if (m_contact_count < 8)
        m_contact_count ++;
}

void    PhoneBook::displayContact(int index) const
{
    const Contact &c = m_contacts[index];
    std::cout << "|";
    std::cout << std::setw(10) << std::right << index << "|";
    std::cout << std::setw(10) << std::right << truncate(c.getFirstName(), 10) << "|";
    std::cout << std::setw(10) << std::right << truncate(c.getLastName(), 10) << "|";
    std::cout << std::setw(10) << std::right << truncate(c.getNickName(), 10) << "|"  << std::endl;
    std::cout << "—————————————————————————————————————————————" << std::endl;

}

void    PhoneBook::displayInformation(int index) const
{
    const Contact &c = m_contacts[index];
    std::cout << c.getFirstName() << std::endl;
    std::cout << c.getLastName() << std::endl;
    std::cout << c.getNickName() << std::endl;
    std::cout << c.getPhoneNumber() << std::endl;
    std::cout << c.getDarkestSecret() << std::endl;
}

void    PhoneBook::searchContacts() const
{
    std::cout << "—————————————————————————————————————————————" << std::endl;
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    std::cout << "—————————————————————————————————————————————" << std::endl;

    for (int i = 0; i < m_contact_count; i++)
        displayContact(i);
    std::cout << "Display contact information by typing index number." << std::endl;
    std::string input;
    safeGetline(input);
    try
    {
        int num = std::stoi(input);
        if (num > m_contact_count - 1)
        {
             std::cout << "Contact does not exist." << std::endl;
             return;
        }
        if (num >= 0 && num <=7)
            displayInformation(num);
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