#include <iostream>
#include <vector>

void backtrack(const std::string &rule, const std::vector<std::string> &words, int index = 0, std::string password = ""){
    if(index == rule.size()){
        std::cout << password << '\n';
        return;
    }
    if(rule[index] == '#'){
        for(int i = 0 ; i < words.size() ; ++i){
            backtrack(rule, words, index + 1, password + words[i]);
        }
    } else{
        for(int i = 0 ; i < 10 ; ++i){
            backtrack(rule, words, index + 1, password + std::to_string(i));
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    while(std::cin >> n){
        std::vector <std::string> dictionary(n);
        for(int i = 0 ; i < n ; ++i){
            std::cin >> dictionary[i];
        }
        int m;
        std::cin >> m;
        std::vector <std::string> rules(m);
        for(int i = 0 ; i < m ; ++i){
            std::cin >> rules[i];
        }
        std::cout << "--\n";
        for(int i = 0 ; i < m ; ++i){
            backtrack(rules[i], dictionary);
        }
    }
    return 0;
}
