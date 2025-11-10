#include "BitcoinExchange.hpp"


void openAndValidateFile(const char* argv[], std::ifstream& inputFile, std::ifstream& dataFile){

    inputFile.open(argv[1]);
    dataFile.open("data.csv");
    if (!inputFile.is_open() || !inputFile.is_open()) {
        std::cerr << "Error: file not found or could not be open." << std::endl;
        exit(1); 
    }
}

int main(int argc, const char* argv[]){
    if (argc != 2){
        std::cerr << "Error: invalid usage. try: ./btc <input.txt" << std::endl;
        exit(1); 
    }
    BitcoinExchange btc;
    std::ifstream inputFile;
    std::ifstream dataFile;
    openAndValidateFile(argv, inputFile, dataFile);
    btc.parseDataFile(dataFile, inputFile);
    btc.checkFileValidity(inputFile, dataFile);

}