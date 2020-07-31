#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;

bool isVowel(unsigned char c){
    if(c >= 'A' && c <= 'Z'){
        c = c - 'A' + 'a';
    }
    std::vector <char> vowels{'a', 'e', 'i', 'o', 'u', 'y'};
    return std::find(vowels.begin(), vowels.end(), c) != vowels.end(); 
}

int main(int argc, char const *argv[])
{
    std::string input;
    std::getline(cin, input);
    char lastChar = 0;
    for(int i = input.length() - 1 ; i >= 0 ; --i){
        if(input[i] != '?' && input[i] != ' '){
            lastChar = input[i];
            break;
        }
    }
    if(isVowel(lastChar)){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
    return 0;
}
