#include "Point.hpp"

Point::Point(): _x(0), _y(0) {};

Point::Point(const float x, const float y) : _x(x), _y(y) {};

Point::Point(const Point& other): _x(other._x), _y(other._y) {};

Point::~Point(){};

float Point::getX () const{
    return _x.toFloat();
}

float Point::getY() const{
    return _y.toFloat();
}
