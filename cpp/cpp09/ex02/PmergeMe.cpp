#include "PmergeMe.hpp"
#include <algorithm>


void printChunks(const std::string& label, const std::vector<Chunk>& chunks) {
    std::cout << label << ":\n";

    for (const Chunk& c : chunks) {
        std::cout << "  Chunk " << c.id << " -> { ";
        for (int n : c.numbers)
            std::cout << n << " ";
        std::cout << "}\n";
    }
}

void sortRecursive(std::vector<int> &vec, size_t pair_size, bool insert_stage)
{

    // ------------------------------------------------------------
    // 1. FIRST PHASE: sort into chunks by pair size and swap chunks based on last number of each chunk (recursion here)
    // ------------------------------------------------------------

    if (insert_stage == false)
    {
        if (pair_size >= vec.size() / 2) {
            insert_stage = true;
            return;
        }
        size_t block_size = pair_size * 2;
        for (size_t i = 0; i + block_size <= vec.size(); i += block_size) {
            // if (i + pair_size * 2 > vec.size()) 
            //     break;
            size_t mid = i + pair_size;
            size_t end = i + block_size;
            if (vec[end - 1] < vec[mid - 1]) {
                std::swap_ranges(
                    vec.begin() + i,
                    vec.begin() + mid,
                    vec.begin() + mid
                );
            }
        }
        sortRecursive(vec, pair_size * 2, false);
    }

    // ------------------------------------------------------------
    // 2. SECOND PHASE: build chunks of numbers based on recursion level
    // ------------------------------------------------------------

    std::vector<Chunk> temp; //this will hold all our numbers in their respective chuncks
    size_t id_counter = 0;
    for (size_t i = 0; i < vec.size(); i += pair_size) {
        size_t end = std::min(i + pair_size, vec.size());
        Chunk c;
        c.id = id_counter++;
        c.numbers.insert(c.numbers.end(), vec.begin() + i, vec.begin() + end);
        temp.push_back(c);
    }


    // ------------------------------------------------------------
    // 3. DIVIDE CHUNKS INTO MAIN AND PENDING for jacobsdahl insertion logic
    // ------------------------------------------------------------

    std::vector<Chunk> main;
	std::vector<Chunk> pend;
    for (size_t i = 0; i < temp.size(); ++i){
        if (i == 0)
            main.push_back(temp[i]); //b1
        else if (i % 2 == 0)
            pend.push_back(temp[i]); //b2, b3, etc...
        else
            main.push_back(temp[i]); //a1, a2, etc...
    }
    // printChunks("MAIN", main);
    // printChunks("PEND", pend);

    while (!pend.empty()){
        
    }
    // ------------------------------------------------------------
    // 4. INSERT PENDING CHUNKS INTO MAIN CHUNKS
    //    (Jacobsthal-driven insertion)
    // ------------------------------------------------------------

     /*


    // NOW AS LONG AS THERE IS STUFF LEFT IN PENDING, INSERT THAT INTO MAIN BY JACOBSDAHL
    {
        while (!pend.empty()) {
        ... insert;
        }
        then when all is inserted:
            ------------------------------------------------------------
            5. WRITE BACK MERGED RESULT INTO vec
            ------------------------------------------------------------
            push everything back into the original vec
    }
   
*/

}

void PmergeMe::sortVector(std::vector<int> &vec) {
    
    sortRecursive(vec, 1, false);
}