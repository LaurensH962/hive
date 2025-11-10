#include "BitcoinExchange.hpp"

void fileError(std::ifstream& inputFile, std::ifstream& dataFile){
    std::cerr << "Error: data.csv file contains mistakes." << std::endl;
    inputFile.close();
    dataFile.close();
    exit(1); 
}

bool BitcoinExchange::validateDate(std::string& date){
    std::tm tm{};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail())
        return false;
    return true;
}

std::map<std::string, double>::const_iterator BitcoinExchange::findClosestDate(const std::string& inputDate) const {
    auto it = btcData.find(inputDate);
    if (it != btcData.end())
        return it;
    it = btcData.lower_bound(inputDate);
    if (it == btcData.begin())
        return btcData.end();
    --it;
    return it;
}

void BitcoinExchange::findAndPrintMoney(std::string date, double value){
    auto it = findClosestDate(date);
    if (it == btcData.end()) {
        std::cout << "Error: No earlier data available for " << date << std::endl;
        return;
    }
    std::cout << date << "|== " << value << " = " << it->second * value << " ==|" << std::endl;
}

void BitcoinExchange::checkFileValidity(std::ifstream& inputFile, std::ifstream& dataFile){
    std::string line;
    getline(inputFile, line);
    if (line != "date | value")
        fileError(inputFile, dataFile);
    std::regex linePattern( R"(^\s*(\d{4}-\d{2}-\d{2})\s*\|\s*(-?\d+(\.\d+)?)\s*$)");
    std::smatch match;
    while (getline(inputFile, line)){
        if (std::regex_match(line, match, linePattern)){
            std::string date = match[1];
            if (!validateDate(date)){
                 std::cout << "Error: bad input |== " << date << " ==|\n";
                 continue;
            }
            double value = std::stod(match[2]);
            if (value < 0){
                 std::cout << "Error: not a positive number.\n";
                 continue;
            }
            if (value > 1000){
                 std::cout << "Error: too large a number.\n";
                 continue;
            }
            findAndPrintMoney(date, value);
        }
        else {
            std::cout << "Error: bad input |== " << line << " ==|\n";
            continue;
        }
    }
    std::cout << "file correct\n";

}

void BitcoinExchange::parseDataFile(std::ifstream& dataFile, std::ifstream& inputFile){
    std::string line;
    getline(dataFile, line);
    if (line != "date,exchange_rate")
        fileError(inputFile, dataFile);
    std::regex linePattern( R"(^\s*(\d{4}-\d{2}-\d{2})\s*,\s*(-?\d+(\.\d+)?)\s*$)");
    std::smatch match;
    while (getline(dataFile, line)){
        if (std::regex_match(line, match, linePattern)) {
            std::string date = match[1];
            if (!validateDate(date))
                fileError(inputFile, dataFile);
            double value = std::stod(match[2]);
            btcData[date] = value;
        }
        else
            fileError(inputFile, dataFile);
    }
}