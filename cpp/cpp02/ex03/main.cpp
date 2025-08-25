#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point point(0.5, 0.4);
    Point a(0, 0);
    Point b(1, 2);
    Point c(-2, 5);
    if (bsp(a, b, c, point))
        std::cout << "\npoint is within triangle\n" << std::endl;
    else
        std::cout << "\npoint is NOT within triangle\n" << std::endl;
    return 0;
}