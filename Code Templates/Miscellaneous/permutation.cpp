#include <iostream>
#include <vector>
#include <set>

void generatePermutations(std::string &sequence, int index, std::vector <std::string> &v){
    if(index == sequence.size()){
        std::cout << sequence << "\n";
        v.push_back(sequence);
    } else{
        generatePermutations(sequence, index + 1, v);
        for(int i = index + 1 ; i < sequence.size() ; ++i){
            std::swap(sequence[index], sequence[i]);
            generatePermutations(sequence, index + 1, v);
            std::swap(sequence[index], sequence[i]);            
        }
    }
}

int main(int argc, char const *argv[])
{
    std::string str = "112";
    std::vector <std::string> permutations;
    generatePermutations(str, 0, permutations);
    std::cout << "Number of permutations " << permutations.size() << "\n";
    for(const std::string &s : permutations){
        std::cout << s << "\n";
    }
    std::set <std::string> uniquePermutations(permutations.begin(), permutations.end());
    std::cout << "Number of unique permutations " << uniquePermutations.size() << "\n";
    for(const std::string &s : uniquePermutations){
        std::cout << s << "\n";
    }
    return 0;
}

