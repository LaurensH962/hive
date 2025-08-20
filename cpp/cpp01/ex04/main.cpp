#include <string>
#include <fstream>
#include <iostream>

bool processFile(std::string filename, std::string search, std::string replace) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Error: Failed to open file." << std::endl;
        return 1;
    }
    std::string outfilename = filename + ".replace";
    std::ofstream out(outfilename);
    if (!out){
        std::cerr << "Error: Failed to create output file";
        return 1;
    }
    std::string str;
    while (std::getline(in, str)){
        size_t pos = 0;
        while ((pos = str.find(search, pos)) != std::string::npos){
            str.erase(pos, search.length());
            str.insert(pos, replace);
            pos += replace.length();
        }
        out << str << "\n";
    }
    in.close();
    out.close();
    return 0;
}

int main( int argc, char *argv[] ) {
    if (argc != 4) {
        std::cerr << "Error: Invalid input." << std::endl
                  << "Usage: ./sedIsForLosers <filename> <string to find> <string to replace with>" << std::endl;
        return 0;
    }
    std::string filename = argv[1];
    std::string search = argv[2];
    std::string replace = argv[3];
    if (search.empty()){
        std::cerr << "Error: search string cannot be empty" << std::endl;
        return 1; 
    }
    if (!processFile(filename, search, replace))
        return 1;
    return 0;
}
