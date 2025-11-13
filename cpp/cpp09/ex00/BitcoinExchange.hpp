#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <ctime>
#include <iomanip> 
#include <chrono>

class BitcoinExchange {
    private:
        std::map<std::string, double> btcData;
    public:
        BitcoinExchange() = default;
        BitcoinExchange(const BitcoinExchange& other) = default;
        BitcoinExchange& operator=(const BitcoinExchange& other) = default;
        ~BitcoinExchange() = default;

        void checkFileValidity(std::ifstream& inputFile, std::ifstream& dataFile);
        void parseDataFile(std::ifstream& dataFile, std::ifstream& inputFile);
        bool validateDate(std::string& date);
        std::map<std::string, double>::const_iterator findClosestDate(const std::string& inputDate) const ;
        void findAndPrintMoney(std::string date, double value);
};