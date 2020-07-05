#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::string s;
    std::cin >> s;
    int max_length = 1;
    int counter = 1;
    for(int i = 0 ; i < s.length() - 1 ; ++i){
        if(s[i] == s[i + 1]){
            ++counter;
            max_length = std::max(max_length, counter);
        } else {
            counter = 1;
        }
    }
    std::cout << max_length << '\n';
    return 0;
}
