#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <iostream>

class Contact {
    public:
        void setFirstName(const std::string &first_name);
        void setLastName(const std::string &last_name);
        void setNickName(const std::string &nick_name);
        void setPhoneNumber(const std::string &phone_number);
        void setDarkestSecret(const std::string &darkest_secret);

        std::string getFirstName() const ;
        std::string getLastName() const ;
        std::string getNickName() const ;
        std::string getPhoneNumber() const ;
        std::string getDarkestSecret() const ;

    private:
        std::string m_first_name;
        std::string m_last_name;
        std::string m_nick_name;
        std::string m_phone_number;
        std::string m_darkest_secret;
};

#endif