#include "ScalarConverter.hpp"

void printChar(const char& inputChar, bool valid) {
    std::cout << "char: ";
    if (!valid){
        std::cout << "impossible" << std::endl;
        return ;
    }
    if (!std::isprint(static_cast<unsigned char>(inputChar))) {
        std::cout << "non displayable" << std::endl;
        return;
    }
   std::cout << inputChar << std::endl;
}

void printInt(const int& inputInt, bool valid) {
    std::cout << "int: ";
    if (!valid) {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << inputInt << std::endl;
}

void printFloat(const float& inputFloat, bool valid) {
    std::cout << "float: ";
    if (!valid) {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (std::isnan(inputFloat)) 
        std::cout << "nanf";
    else if (std::isinf(inputFloat))
        if (inputFloat < 0)
            std::cout << "-inff"; 
        else
            std::cout << "inff"; 
    else 
        std::cout << std::fixed << std::setprecision(1) << inputFloat << "f";
    std::cout << std::endl;
}

void printDouble(const double& inputDouble, bool valid) {
    std::cout << "double: ";
    if (!valid) {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (std::isnan(inputDouble)) 
        std::cout << "nan";
    else if (std::isinf(inputDouble))
        if (inputDouble < 0)
            std::cout << "-inf"; 
        else
            std::cout << "inf"; 
    else 
        std::cout << inputDouble;
    std::cout << std::endl;
}

void printInvalid() {
    std::cout   << "not valid literal" << std::endl;
}

InputType findType(const std::string& input){
    std::string s;
    for (char c : input){
        if (!std::isspace((unsigned char) c))
            s += c;
    }
    if (s.size() == 1 && std::isprint((unsigned char) s[0]) && !std::isdigit((unsigned char) s[0]))
        return InputType::Char;
    std::string lower;
    for (char c : s) {
        lower += std::tolower((unsigned char) c);
    }
    if (lower == "nanf" || lower == "inff" || lower == "-inff" || lower == "+inff")
        return InputType::Float;
    if (lower == "nan" || lower == "inf" || lower == "-inf" || lower == "+inf")
        return InputType::Double;
    try {
        size_t idx;
        std::stoi(input, &idx);
        if (idx == input.size())
            return InputType::Int;
    } catch (...) {}
    if (!(input.find('.') != std::string::npos)) {
        return InputType::Invalid;
    }
    bool isFloatSuffix = (lower.back() == 'f');
    std::string numPart = input;
    if (isFloatSuffix)
        numPart.pop_back();
    try {
        size_t idx;
        std::stod(numPart, &idx);
        if (idx == numPart.size()) {
            return isFloatSuffix ? InputType::Float : InputType::Double;
        }
    } catch (...) {}
    return InputType::Invalid;
}


void ScalarConverter::convert(std::string input) {
    switch (findType(input)){
        case InputType::Char: {
            char c = input[0];
            printChar(c, true);
            printInt(static_cast<int>(c), true);
            printFloat(static_cast<float>(c), true);
            printDouble(static_cast<double>(c), true);
            break;
        }
        case InputType::Int: {
            try {
                int value = stoi(input);
                if (value < 0 || value > 255)
                    printChar(0, false);
                else
                    printChar(static_cast<unsigned char>(value), true);
                printInt(value, true);
                printFloat(static_cast<float>(value), true);
                printDouble(static_cast<double>(value), true);
            }
            catch (const std::out_of_range&) {
                printInvalid();
            }
            catch (const std::invalid_argument&) {
                printInvalid();
            }
            break;
        }
        case InputType::Float: {
            try {
                float value = stof(input);
                if (value < 0 || value > 255)
                    printChar(0, false);
                else
                    printChar(static_cast<unsigned char>(value), true);
                if (value < static_cast<float>(std::numeric_limits<int>::min()) ||
                        value > static_cast<float>(std::numeric_limits<int>::max()) ||
                        std::isnan(value) || std::isinf(value))
                    printInt(0, false);
                else
                    printInt(static_cast<int>(value), true);
                printFloat(static_cast<float>(value), true);
                printDouble(static_cast<double>(value), true);
            }
            catch (const std::out_of_range&) {
                printInvalid();
            }
            catch (const std::invalid_argument&) {
                printInvalid();
            }
            break;
        }
        case InputType::Double: {
            try {
                double value = stod(input);
                if (value < 0 || value > 255)
                    printChar(0, false);
                else
                    printChar(static_cast<unsigned char>(value), true);
                if (value < static_cast<float>(std::numeric_limits<int>::min()) ||
                        value > static_cast<float>(std::numeric_limits<int>::max()) ||
                        std::isnan(value) || std::isinf(value))
                    printInt(0, false);
                else
                    printInt(static_cast<int>(value), true);
                if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
                    printFloat(0, false);
                else
                    printFloat(static_cast<float>(value), true);
                printDouble(value, true);
            }
            catch (const std::out_of_range&) {
                printInvalid(); 
            }
            catch (const std::invalid_argument&) {
                printInvalid();
            }
            break;
        }
        case InputType::Invalid: {
            printInvalid();
            break;
        }
    }
}