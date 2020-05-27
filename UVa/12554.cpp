#include <iostream>
#include <vector>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::string lyrics = "Happy birthday to you Happy birthday to you Happy birthday to Rujia Happy birthday to you";
    std::vector <std::string> tokens;
    tokens.reserve(16);
    std::stringstream ss(lyrics);
    std::string token;
    while(ss >> token){
        tokens.emplace_back(token);
    }
    int n;
    std::cin >> n;
    std::vector <std::string> persons(n);
    for(int i = 0 ; i < n ; ++i){
        std::cin >> persons[i];
    }
    int token_index = 0, people_index = 0;
    bool people_flag = false;
    while(true){
        std::cout << persons[people_index++] << ": " << tokens[token_index++] << '\n';
        if(token_index == 16 && people_flag) break;
        token_index %= 16; 
        if(people_index == n) {
            people_index = 0;
            people_flag = true;
        }
    }
    return 0;
}
