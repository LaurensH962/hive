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

void sortRecursive(std::vector<int> &vec, size_t pair_size, bool& insert_stage)
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
        sortRecursive(vec, pair_size * 2, insert_stage);
    }

    // ------------------------------------------------------------
    // 2. SECOND PHASE: build chunks of numbers based on recursion level
    // ------------------------------------------------------------

    std::vector<Chunk> temp; //this will hold all our numbers in their respective chuncks
    size_t id_counter = 0;
    for (size_t i = 0; i < vec.size(); i += pair_size) {
        size_t end = i + pair_size;
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
    printChunks("MAIN", main);
    printChunks("PEND", pend);


    // ------------------------------------------------------------
    // 4. INSERT PENDING CHUNKS INTO MAIN CHUNKS
    // ------------------------------------------------------------
    size_t jac = 3;
    size_t jac_prev = 1;
    while (!pend.empty()){
        size_t amount = jac - jac_prev;
       for (size_t i = 0; i < amount && !pend.empty(); i++){
            Chunk toInsert = pend.front();
            int top_max = toInsert.numbers.back();

            auto it = main.begin();
            for (; it != main.end(); ++it){
                std::cout << "pend max = " << top_max << ", main max = " << it->numbers.back() << std::endl;
                if (top_max < it->numbers.back())
                    break;
            }

            main.insert(it, toInsert);
            pend.erase(pend.begin());
        }
        size_t jac_temp = jac + 2 * jac_prev;
        jac_prev = jac;
        jac = jac_temp;
    }
    // printChunks("MAIN", main);
    std::vector<int> result;

    // Push chunks from main in order
    for (const Chunk& c : main) {
        result.insert(result.end(), c.numbers.begin(), c.numbers.end());
    }

    // Append leftovers (unchanged)
    size_t leftovers_start = (vec.size() / pair_size) * pair_size;
    result.insert(result.end(), vec.begin() + leftovers_start, vec.end());

    // Replace vec with the final sorted content
    vec = std::move(result);
    std::cout << "VECTOR = ";
    for (int n: vec)
        std::cout << n << ' ';
    std::cout << std::endl;
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
    bool insert_stage = false;
    sortRecursive(vec, 1, insert_stage);
}