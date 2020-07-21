#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::string input;
    std::cin >> input;
    std::vector <int> freq(26, 0);
    for(char c : input){
        ++freq[c - 'a'];
    }
    bool beautiful = true;
    for(int f : freq){
        if(f % 2){
            beautiful = false;
            break;
        }
    }
    if(beautiful){
        std::cout << "Yes\n";
    } else{
        std::cout << "No\n";
    }
    return 0;
}
