#include <string> 
#include <iostream>

int main( void )
{
    std::string brain_str = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain_str;
    std::string& stringREF = brain_str;

    std::cout << "memory addresses of brain_str, stringPTR and stringREF are:\n" 
              << &brain_str << "\n"
              << stringPTR << "\n"
              << &stringREF << std::endl;

    std::cout << "values of brain_str, stringPTR and stringREF are:\n" 
              << brain_str << "\n"
              << *stringPTR << "\n"
              << stringREF << std::endl;
              
    return (0);
}