#include "PmergeMe.hpp"
#include <algorithm>


void PmergeMe::sortVector(std::vector<int> &vec) {
    //lambda function to recursivly with (&self, pairsize, bool to check if inserion stage is reached)
    /*
    // FIRST SORT INTO PAIRS WITH PAIRSIZE if insertion is false
    {
        for loop to go through vec and divide into pairs with pairsize {
            now make pairs throughout the vector
            if vec.size/2 < pairize{
                insertion bool = true;
                return; (depth of recursion reached)
            }
            now check the last values of each pair and swap if necessary
        }  
    }
    // NOW BUILD THE CHUNKS WITHIN THE RECUSION LEVEL YOU ARE IN RN
    struct Chunk { std::vector<int> data; size_t id; }; // this will be used for each chunk of pairs, so we can insert it at the specific jacobsdahl number
    {
        std::vector<VChunk> temp;
        for loop to push into  temp chunk all subvectors by pairsize so this one chunk has inside all smaller ranges of number
    }
    create main chunk and pending chunk and push respective a and p chunks inside according to their index
    {
        std::vector<VChunk> pend;
		std::vector<VChunk> main;
		for (size_t i = 0; i < temp.size(); ++i) {
			if (i == 0)            main.push_back(temp[i]);   // b1
			else if (i % 2 == 0)   pend.push_back(temp[i]);   // b2, b3, ...
			else                   main.push_back(temp[i]);   // a1, a2, ...
		}
    }
    
    // NOW AS LONG AS THERE IS STUFF LEFT IN PENDING, INSERT THAT INTO MAIN BY JACOBSDAHL
    {
        while (!pend.empty()) {
        ... insert;
        }
        then when all is inserted:
            push everything back into the original vec
    }
    */
   //call lamda func 
}