#include <iostream>

int main(int argc, char const *argv[])
{
    std::string input;
    std::cin >> input;
    std::string current;
    for(char c : input){
        if(c == 'B'){
            if(!current.empty()) current.pop_back();
        } else{
            current += c;
        }
    }
    std::cout << current << '\n';
    return 0;
}
