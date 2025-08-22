#include "Fixed.hpp"

Fixed::Fixed() : _data(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int data){
    std::cout << "Int constructor called" << std::endl;
    _data = data << _fractBits;
}

Fixed::Fixed(const float data){
    std::cout << "Float constructor called" << std::endl;
    _data = roundf(data * (1 << _fractBits));
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _data(other._data){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return _data;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    _data = raw;
}

float Fixed::toFloat( void ) const{
    return static_cast<float>(_data) / (1 << _fractBits);
}
int Fixed::toInt( void ) const{
    return _data >> _fractBits;
}

Fixed& Fixed::operator++(){
    _data += 1;
    return *this;
}

Fixed& Fixed::operator--(){
    _data -= 1;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed temp(*this);
    _data += 1;
    return temp;
}

Fixed Fixed::operator--(int){
     Fixed temp(*this);
    _data -= 1;
    return temp;
}

bool Fixed::operator<(const Fixed& other) const{
    return this->_data < other._data;
}    

bool Fixed::operator>(const Fixed& other) const{
    return this->_data > other._data;
}

bool Fixed::operator<=(const Fixed& other) const{
    return this->_data <= other._data;
}

bool Fixed::operator>=(const Fixed& other) const{
    return this->_data >= other._data;
}

bool Fixed::operator==(const Fixed& other) const{
    return this->_data == other._data;
}    

bool Fixed::operator!=(const Fixed& other) const{
    return this->_data != other._data;
}    

Fixed Fixed::operator+(const Fixed& other) const{
    Fixed temp;
    temp._data = this->_data + other._data;
    return temp;
}

Fixed Fixed::operator-(const Fixed& other) const{
    Fixed temp;
    temp._data = this->_data - other._data;
    return temp;
}

Fixed Fixed::operator*(const Fixed& other) const{
    Fixed temp;
    temp._data = ( (long long) this->_data * other._data ) >> _fractBits ;
    return temp;
}

Fixed Fixed::operator/(const Fixed& other) const{
    Fixed temp;
    temp._data = ( (long long) this->_data << _fractBits ) / other._data;
    return temp;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    return (a._data >= b._data) ? a : b;
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}