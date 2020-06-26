#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <map>

std::pair<std::vector<char>,std::vector<int>> generate_frequency(const std::string &sequence){
    std::map <char, int> unique_characters;
    for(char c : sequence){
        ++unique_characters[c];
    }
    std::vector <char> characters(unique_characters.size());
    std::vector <int> frequency(unique_characters.size());
    int index = 0;
    for(const auto &c : unique_characters){
        characters[index] = c.first;
        frequency[index] = c.second;
        ++index;
    }
    return {characters, frequency};
}

/* the following function generates all the unique permutations of an input string "sequence"
 * limitations:
 *    - generated permutations have the same length as the input string (no size parameter)
 *    - works only for english alphabet strings (modify with vector if alphanumeric string is given as input)
 */

void backtrack(const std::string &sequence, const std::vector <char> &characters, std::vector <int> &frequency, std::vector<std::string> &permutations, std::string permutation = ""){
    if(permutation.length() == sequence.length()){
        //std::cout << permutation << '\n';
        permutations.emplace_back(permutation);
        return;
    }
    for(int i = 0 ; i < characters.size() ; ++i){
        if(frequency[i] > 0){
            --frequency[i];
            backtrack(sequence, characters, frequency, permutations, permutation + characters[i]);
            ++frequency[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    // keep track of character count in given string
    std::string sequence = "aabbc";
    std::vector <char> characters;
    std::vector <int> frequency;
    std::tie(characters, frequency) = generate_frequency(sequence);
    std::vector <std::string> permutations;
    backtrack(sequence, characters, frequency, permutations);
    std::cout << "number of unique permutations " << permutations.size() << '\n';
    for(int i = 0 ; i < permutations.size() ; ++i){
        std::cout << permutations[i] << '\n';
    }
    return 0;
}
