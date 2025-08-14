#include "Contact.hpp"

void Contact::setFirstName(const std::string &first_name) {
    m_first_name = first_name;
}

void Contact::setLastName(const std::string &last_name) {
    m_last_name = last_name;
}

void Contact::setNickName(const std::string &nick_name) {
    m_nick_name = nick_name;
}

void Contact::setPhoneNumber(const std::string &phone_number) {
    m_phone_number = phone_number;
}

void Contact::setDarkestSecret(const std::string &darkest_secret) {
    m_darkest_secret = darkest_secret;
}

std::string Contact::getFirstName() const {
    return m_first_name;
}

std::string Contact::getLastName() const {
    return m_last_name;
}

std::string Contact::getNickName() const {
    return m_nick_name;
}

std::string Contact::getPhoneNumber() const {
    return m_phone_number;
}

std::string Contact::getDarkestSecret() const {
    return m_darkest_secret;
}