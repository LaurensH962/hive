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

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        bool operator<(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed& operator++();
        Fixed& operator--();

        Fixed operator++(int);
        Fixed operator--(int);

        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;

        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
