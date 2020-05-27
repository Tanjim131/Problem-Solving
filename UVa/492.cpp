#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

inline bool isVowel(char c){
    std::vector <char> voewls({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
    return std::find(voewls.begin(), voewls.end(), c) != voewls.end();
}

inline bool isAlphabet(char c){
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    std::string s;
    while(std::getline(std::cin, s)){
        std::string answer;
        int i = 0;
        while(i < s.size()){
            if(isAlphabet(s[i])){
                char first = s[i];
                if(isVowel(first)){
                    answer += s[i++];
                } else {
                    ++i;
                }
                while(i < s.size() && isAlphabet(s[i])) answer += s[i++];
                if(!isVowel(first)){
                    answer += first;
                } 
                answer += "ay";
            } else{
                answer += s[i++];
            }
        }
        std::cout << answer << '\n';
    }
    return 0;
}
