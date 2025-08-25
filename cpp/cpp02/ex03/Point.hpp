#pragma once

#include "Fixed.hpp"

class Point{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        Point& operator=(const Point& other) = delete;
        ~Point();
        float getX () const;
        float getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);