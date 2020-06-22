#include <iostream>

// all two length substrings are repeated
// so all the letter between index 1 and length() - 1 are repeated exactly twice
// so from index 1 to length() - 1 of given string b, consider only one count of each letter

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        std::string b;
        std::cin >> b;
        std::cout << b[0]; // first character
        for(int i = 1 ; i < b.length() - 1 ; i += 2){
            // increase by 2
            // count single occurrence of each character in this range
            std::cout << b[i];
        }
        std::cout << b[b.length() - 1] << '\n'; // last character
    }
    return 0;
}
