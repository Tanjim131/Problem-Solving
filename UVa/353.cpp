#include <iostream>
#include <unordered_set>

bool isPalindrome(const std::string &str){
    for(int i = 0 ; i < str.length() ; ++i){
        if(str[i] != str[str.length() - 1 - i]) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    std::string input;
    while(std::getline(std::cin, input)){
        std::unordered_set<std::string> us;
        for(int i = 0 ; i < input.size() ; ++i){
            for(int j = i ; j < input.size() ; ++j){
                std::string substring(input.substr(i, j - i + 1));
                us.insert(substring);
            }
        }
        int counter = 0;
        for(const std::string &substring : us){
            if(isPalindrome(substring)) ++counter;
        }
        std::cout << "The string '" << input << "' contains " << counter << " palindromes.\n";
    }
    return 0;
}
