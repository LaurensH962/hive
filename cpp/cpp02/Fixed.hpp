#pragma once

#include <iostream>

class Fixed{
    private:
        int data;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
};