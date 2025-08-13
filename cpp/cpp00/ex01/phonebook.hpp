#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>

class Contact {
    public:
        void set_first_name(const std::string &first_name) {m_first_name = first_name;}
        void set_last_name(const std::string &last_name) {m_last_name = last_name;}
        void set_nick_name(const std::string &nick_name) {m_nick_name = nick_name;}
        void set_phone_number(const std::string &phone_number) {m_phone_number = phone_number;}
        void set_darkest_secret(const std::string &darkest_secret) {m_darkest_secret = darkest_secret;}

        std::string get_first_name() const {return m_first_name;}
        std::string get_last_name() const {return m_last_name;}
        std::string get_nick_name() const {return m_nick_name;}
        std::string get_phone_number() const {return m_phone_number;}
        std::string get_darkest_secret() const {return m_darkest_secret;}

    private:
        std::string m_first_name;
        std::string m_last_name;
        std::string m_nick_name;
        std::string m_phone_number;
        std::string m_darkest_secret;
};

class PhoneBook {
    public:
        void add_contact();
        void search_contacts() const;
        void display_contact(int index) const;
        void display_information(int index) const;

    private:
        Contact m_contacts[8];
        int m_next_index = 0;
        int m_contact_count = 0;
};

void        safe_getline(std::string &input);
void        display_start_prompt();
std::string truncate(std::string str, size_t width);

#endif