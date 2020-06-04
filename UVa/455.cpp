#include <iostream>

int main(int argc, char const *argv[])
{
    int T, k = 0;
    std::cin >> T;
    while(T--){
        std::string input;
        std::cin >> input;
        if(k > 0) std::cout << '\n';
        for(int i = 0 ; i < input.length() ; ++i){
            int substring_length = i + 1;
            if(input.length() % substring_length) continue;
            // check if this substring is the one with the smallest period
            std::string substring(input.substr(0, substring_length));
            int times = input.length() / substring.length();
            std::string concat;
            for(int i = 0 ; i < times ; ++i){
                concat += substring;
            }
            if(concat == input){
                std::cout << substring.length() << '\n';
                break;
            }
        }
        ++k;
    }
    return 0;
}
