#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <map>

std::pair<std::vector<char>, std::vector<int>> generate_unique_characters_and_frequency(const std::string &sequence){
    std::map <char, int> unique_characters;
    for(char c : sequence){
        ++unique_characters[c]; // keep track of each unique character with associated count
    }
    std::vector <char> characters(unique_characters.size()); // list of unique characters
    std::vector <int> frequency(unique_characters.size()); // count of each character
    int index = 0;
    for(const auto &c : unique_characters){
        characters[index] = c.first;
        frequency[index] = c.second;
        ++index;
    }
    return {characters, frequency};
}

/* the following function generates all the  combinations of an input string "sequence" of length "k"
 * limitations:
 *    - works only for english alphabet strings (modify with vector if alphanumeric string is given as input)
 */

void generate_combination(const std::string &sequence, int k, const std::vector<char> &characters, std::vector <int> &frequency, std::string combination = "", int start_from = 0){
    if(combination.length() == k){
        std::cout << combination << '\n';
        return;
    }
    for(int i = start_from ; i < characters.size() ; ++i){
        if(frequency[i] > 0){ 
            --frequency[i];
            generate_combination(sequence, k, characters, frequency, combination + characters[i], i);
            ++frequency[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    // keep track of character count in given string
    std::string sequence = "eeeeaabbb";
    std::sort(sequence.begin(), sequence.end());
    std::vector <char> characters;
    std::vector <int> frequency;
    std::tie(characters, frequency) = generate_unique_characters_and_frequency(sequence);
    int k = 3;
    generate_combination(sequence, k, characters, frequency);
    return 0;
}
