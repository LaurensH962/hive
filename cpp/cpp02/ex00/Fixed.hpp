#pragma once

#include <iostream>

class Fixed{
    private:
        int _data;
        static const int _fractBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits(int const raw);
};