#include <iostream>
#include <vector>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::string input;
    while(std::getline(std::cin, input)){
        std::stringstream ss(input);
        std::vector <std::string> tokens;
        std::string token;
        while(ss >> token) {
            tokens.emplace_back(token);
        }
        for(int i = 0 ; i < tokens.size() ; ++i){
            for(int j = tokens[i].length() - 1 ; j >= 0 ; --j){
                std::cout << tokens[i][j];
            }
            if(i != tokens.size() - 1) std::cout << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
