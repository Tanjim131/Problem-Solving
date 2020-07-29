#include <iostream>
#include <algorithm>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::string input, normalized;
    std::cin >> input;
    std::replace_if(input.begin(), input.end(), [](char c){ return c == '/'; } , ' ');    
    std::istringstream iss(input);
    std::string token;
    while(iss >> token){
        normalized += "/" + token;
    }
    std::cout << (normalized.empty() ? "/" : normalized) << '\n';
    return 0;
}
