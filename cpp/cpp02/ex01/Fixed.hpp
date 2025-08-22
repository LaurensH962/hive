#pragma once

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int _data;
        static const int _fractBits = 8;
    public:
        Fixed();
        Fixed(const int data);
        Fixed(const float data);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);