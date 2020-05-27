#include <iostream>

int main(int argc, char const *argv[])
{
    std::string s, t;
    while(std::cin >> s >> t){
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                ++i;
            } 
            ++j;
        }
        if(i == s.size()){
            std::cout << "Yes\n";
        } else{
            std::cout << "No\n";
        }
    }
    return 0;
}
