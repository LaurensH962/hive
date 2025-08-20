#include "Harl.hpp"

int main( void ){
    std::cout << "Harl wants to complain about some shit.... what level should it be?" << std::endl
              << "try DEBUG INFO WARNING or ERROR" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    Harl harl;
    harl.complain(input);
    return 0;
}