#include <iostream>
#include <unordered_map>

std::unordered_map<char,char> generateReverse(){
     std::unordered_map<char,char> reverseList = {
        {'A', 'A'},
        {'E', '3'},
        {'H', 'H'},
        {'I', 'I'},
        {'J', 'L'},
        {'L', 'J'},
        {'M', 'M'},
        {'O', 'O'},
        {'S', '2'},
        {'T', 'T'},
        {'U', 'U'},
        {'V', 'V'},
        {'W', 'W'},
        {'X', 'X'},
        {'Y', 'Y'},
        {'Z', '5'},
        {'1', '1'},
        {'2', 'S'},
        {'3', 'E'},
        {'5', 'Z'},
        {'8', '8'}
    };
    return reverseList;
}

bool isRegularPalindrome(const std::string &str){
    for(int i = 0 ; i < str.length() / 2 ; ++i){
        if(str[i] != str[str.length() - 1 - i]) return false;
    }
    return true;
}

bool isMirroredString(const std::string &str, const std::unordered_map<char,char> &reverseList){
    for(int i = 0 ; i <= str.length() / 2 ; ++i){
        char first = str[i];
        char last = str[str.length() - 1 - i];
        if(reverseList.find(first) == reverseList.end()) return false;
        char mirrored = reverseList.at(first);
        if(mirrored != last) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    std::unordered_map <char,char> reverseList = generateReverse();
    std::string input;
    while(std::getline(std::cin, input)){
        bool retPalindrome = isRegularPalindrome(input);
        bool retMirrored = isMirroredString(input, reverseList);
        if(!retPalindrome && !retMirrored){
            std::cout << input << " -- is not a palindrome.\n";
        } else if(retPalindrome && !retMirrored){
            std::cout << input << " -- is a regular palindrome.\n";
        } else if(retMirrored && !retPalindrome){
            std::cout << input << " -- is a mirrored string.\n";
        } else{
            std::cout << input << " -- is a mirrored palindrome.\n";
        }
        std::cout << '\n';
    }
    return 0;
}
