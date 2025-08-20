#include "Harl.hpp"


void Harl::debug( void ){
    std::cout << "3 + 3 = 9" << std::endl;
}

void Harl::info( void ){
    std::cout << "No really trust me, 3 + 3 = 9 I double checked" << std::endl;
}

void Harl::warning( void ){
    std::cout << ".... I am disappointed in you" << std::endl;
}

void Harl::error( void ){
    std::cout << "go back to basic math!!! 3 + 3 is 9 I a computer must know better than you puny human.. pfff!" << std::endl;
}

void Harl::complain( std::string level ){

    void(Harl::*FuncPtr[])(void) = {
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error};
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    for (int i = 0; i < 4; i++){
        if (levels[i] == level){
            (this->*FuncPtr[i])();
            return;
        }
    }
}