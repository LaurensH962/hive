#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include "Contact.hpp"


class PhoneBook {
    public:
        void addContact();
        void searchContacts() const;
        void displayContact(int index) const;
        void displayInformation(int index) const;

    private:
        Contact m_contacts[8];
        int m_next_index = 0;
        int m_contact_count = 0;
};

void        safeGetline(std::string &input);
void        displayStartPrompt();
std::string truncate(std::string str, size_t width);

#endif