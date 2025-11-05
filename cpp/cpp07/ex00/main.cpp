#include "Templates.hpp"
#include <iostream>

int main(void) {
    {
        std::cout << "///// TEST 1 /////\n\n";
        int a = 1;
        int b = 2;
        std::cout << "swapping a = " << a << ", and b = " << b << std::endl;
        swap(a, b);
        std::cout << "new a = " << a << ", and new b = " << b << std::endl;

        int c = min(a, b);
        std::cout << "min of a and b = " << c << std::endl;

        int d = max(a, b);
        std::cout << "max of a and b = " << d << std::endl;
    }
    {
        std::cout << "\n\n///// TEST 2 /////\n\n";
        int a = 1;
        int b = 1;
        std::cout << "swapping a = " << a << ", and b = " << b << std::endl;
        swap(a, b);
        std::cout << "new a = " << a << ", and new b = " << b << std::endl;

        int c = min(a, b);
        std::cout << "min of a and b = " << c << std::endl;

        int d = max(a, b);
        std::cout << "max of a and b = " << d << std::endl;
    }

    {
        std::cout << "\n\n///// TEST 3 /////\n\n";
        float a = 1.2;
        float b = 1;
        std::cout << "swapping a = " << a << ", and b = " << b << std::endl;
        swap(a, b);
        std::cout << "new a = " << a << ", and new b = " << b << std::endl;

        float c = min(a, b);
        std::cout << "min of a and b = " << c << std::endl;

        float d = max(a, b);
        std::cout << "max of a and b = " << d << std::endl;
    }

    {
        std::cout << "\n\n///// TEST 4 /////\n\n";
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "string c";
        std::string d = "string d";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
        return 0;
    }

}