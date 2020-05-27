#include <iostream>

int main(int argc, char const *argv[])
{
    std::string input;
    while(std::getline(std::cin, input)){
        for(int i = 0 ; i < input.length() ; ++i){
           std::cout << static_cast <char> (input[i] - 7);
        }
        std::cout << '\n';
    }
    return 0;
}
