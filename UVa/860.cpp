#include <iostream>
#include <sstream>
#include <cctype>
#include <cmath>
#include <cctype>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <vector>

/*
Some tips:

A word is a string of chars, none of which is one of the following 14: ',', '.', ':', ';', '!', '?', '"', '(', ')', ' ', '\t', '\n', (char)EOF and '\0'. 
All other 256-14 characters can (and probably will) appear in a word.
So "don't", "do_not", "do\anot", "d19175", "do;nt" are all single, different words. 
Don't rely on library functions isspace(), isalnum(), iscntrl(), etc. !

"master_b" is the same as "Master_B", "mAsTeR_B", etc. but "***End_of_Text***" is not the same as "***END_OF_TEXT***". (Note there are 3 stars trailing this word, not 4 as in the output description).

There is no white space at the end of the input, the last '*' of "****END_OF_INPUT****" is immediately followed by EOF. 
My first program went into an endless loop waiting for the final white space that never came. 
(While I was thinking my algorithm was slow :oops:)

Hope it helps.

Credit: little joey (UVa forum)

*/

inline bool isGarbage(unsigned char c){
    std::vector <char> garbage{',', '.', ':', ';', '!', '?', '"', '(', ')', ' '};
    return std::find(garbage.begin(), garbage.end(), c) != garbage.end();
}

std::string processToken(std::string &token){
    std::string word;
    word.reserve(20);
    
    for(int i = 0 ; i < token.length() ; ++i){
        if(!isGarbage(token[i])){
            word += std::tolower(token[i]); // case insensitive
        }
    }

    return word;
}

void processLine(std::string &line, std::unordered_map <std::string, int> &frequency, int &totalWords){
    std::replace_if(line.begin(), line.end(), isGarbage, ' '); // for words trapped inside garbage characters
    
    std::istringstream iss(line);
    std::string token;
    while(iss >> token){
        std::string word = processToken(token);
        ++frequency[word];
        ++totalWords;
    }
}

int main(){
    std::string input;
    while(std::getline(std::cin, input) && input != "****END_OF_INPUT****"){

        if(input == "****END_OF_TEXT****"){
            std::cout << "0 0.0 0\n"; // empty text
            continue;
        }
  
        std::unordered_map <std::string, int> frequency;
        frequency.reserve(100000);

        int totalWords = 0;

        processLine(input, frequency, totalWords);
        while(std::getline(std::cin, input) && input != "****END_OF_TEXT****"){
            if(!input.empty()){
                processLine(input, frequency, totalWords);
            }
        }

        double max_entropy = std::log10(totalWords);
        double constant = totalWords * max_entropy;

        double sum = 0.0;
        for(const auto &word : frequency){
            int word_frequency = word.second;
            sum += word_frequency * std::log10(word_frequency);
        }

        double entropy = 1.0 / totalWords * (constant - sum);
        double relative_entropy = entropy / max_entropy * 100.0;   

        std::cout << totalWords << " " << std::fixed << std::setprecision(1) << entropy << " " << static_cast<int>(std::round(relative_entropy)) << '\n';
    }
    return 0;
}
