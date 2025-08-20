#include "Harl.hpp"


void Harl::debug( void ){
    std::cout   << "[DEBUG]" << std::endl
                << "3 + 3 = 9" << std::endl;
}

void Harl::info( void ){
    std::cout   << "[INFO]" << std::endl
                << "No really trust me, 3 + 3 = 9 I double checked" << std::endl;
}

void Harl::warning( void ){
    std::cout   << "[WARNING]" << std::endl
                << ".... I am disappointed in you" << std::endl;
}

void Harl::error( void ){
    std::cout   << "[ERROR]" << std::endl
                << "go back to basic math!!! 3 + 3 is 9 I a computer must know better than you puny human.. pfff!" << std::endl;
}

void Harl::complain( const std::string& level ){

    void(Harl::*FuncPtr[])(void) = {
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error};
    switch (findComplaintLevel(level))
    {
        case ComplaintLevel::DEBUG:
            (this->*FuncPtr[0])();
            [[fallthrough]];
        case ComplaintLevel::INFO:
            (this->*FuncPtr[1])();
            [[fallthrough]];
        case ComplaintLevel::WARNING:
            (this->*FuncPtr[2])();
            [[fallthrough]];
        case ComplaintLevel::ERROR:
            (this->*FuncPtr[3])();
            break;
        case ComplaintLevel::NOTHING:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}