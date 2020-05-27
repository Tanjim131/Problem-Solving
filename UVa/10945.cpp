#include <iostream>

inline bool isPalindrome(const std::string &parse){
    for(int i = 0 ; i < parse.length() / 2 ; ++i){
        if(parse[i] != parse[parse.length() - 1 - i]) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    std::string line;
    while(std::getline(std::cin, line)){
        if(line == "DONE") break;
        std::string parse;
        parse.reserve(line.length());
        for(int i = 0 ; i < line.length() ; ++i){
            if(line[i] >= 'A' && line[i] <= 'Z'){
                parse += line[i] - 'A' + 'a';
            } else if(line[i] >= 'a' && line[i] <= 'z') {
                parse += line[i];
            }
        }
        if(isPalindrome(parse)){
            std::cout << "You won't be eaten!\n";
        } else{
            std::cout << "Uh oh..\n";
        }
    }
    return 0;
}
