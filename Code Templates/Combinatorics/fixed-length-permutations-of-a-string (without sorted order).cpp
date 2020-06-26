#include <iostream>
#include <vector>

/* the following function generates all the unique permutations of an input string "sequence"
 * limitations:
 *    - doesn't generate the permutations in lexicographical order (when there are repeated characters in input string)
 *    - generated permutations have the same length as the input string (no size parameter)
 *    - works only for english alphabet strings (modify with vector if alphanumeric string is given as input)
 */

void generatePermutations(std::string &sequence, int index, std::vector <std::string> &v){
    if(index == sequence.size()){
        //std::cout << sequence << "\n";
        v.emplace_back(sequence);
    } else{
        generatePermutations(sequence, index + 1, v);
        for(int i = index + 1 ; i < sequence.size() ; ++i){
            if(sequence[index] != sequence[i]){ // uncomment this condition if you don't want unique permutations
                std::swap(sequence[index], sequence[i]);
                generatePermutations(sequence, index + 1, v);
                std::swap(sequence[index], sequence[i]);            
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    std::string str = "abc";
    std::vector <std::string> permutations;
    generatePermutations(str, 0, permutations);
    std::cout << "Number of permutations " << permutations.size() << "\n";
    for(const std::string &s : permutations){
        std::cout << s << "\n";
    }
    return 0;
}

