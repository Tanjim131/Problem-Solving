#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#include <string>

void printSolution(std::vector <std::string> &taken){
    for(int i = 0 ; i < taken.size() ; ++i){
        std::cout << taken[i];
        if(i != taken.size() - 1) std::cout << " ";
    }
    std::cout << '\n';
}

bool doesViolate(const std::vector <std::string> &taken, const std::string &choice, const std::vector <std::pair<std::string, std::string>> &prohibited){
    for(int i = 0 ; i < taken.size() ; ++i){
        auto it = std::find_if(prohibited.begin(), 
                                prohibited.end(),
                                [&](const std::pair<std::string, std::string> &prohibited_pair){
                                    return taken[i] == prohibited_pair.first && choice == prohibited_pair.second;
                                }
                            );
        if(it != prohibited.end()) return true;
    }
    return false;
}

void backtrack(const std::vector <std::string> &topics, const std::vector <std::pair<std::string, std::string>> &prohibited, int target_size, int index = 0, std::vector <std::string> taken = std::vector <std::string>()){
    if(taken.size() == target_size){
        printSolution(taken);
        return;
    }

    if(index == topics.size()) return;

    if(!doesViolate(taken, topics[index], prohibited)){
        // check if taking this option will violate the constraints
        taken.emplace_back(topics[index]);
        backtrack(topics, prohibited, target_size, index + 1, taken);
        taken.pop_back();
        backtrack(topics, prohibited, target_size, index + 1, taken);
    } else{
        // choice violates the constraint, ignore and move forward
        backtrack(topics, prohibited, target_size, index + 1, taken);
    }
}

bool isSwapNeeded(const std::string &a, const std::string &b){
    if(a.length() == b.length()){
        return b < a;
    }
    return b.length() > a.length();
}

void convertToUpperCase(std::string &str){
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

struct TopicsComparator { 
   bool operator()(const std::string &a, const std::string &b){
        if(a.length() == b.length()) return a < b;
        return a.length() > b.length();
   }
};

int main(int argc, char const *argv[])
{
    int T, k = 0;
    std::cin >> T;
    while(T--){
        int t,p,s;
        std::cin >> t >> p >> s;
        std::vector <std::string> topics(t);
        for(int i = 0 ; i < t ; ++i){
            std::cin >> topics[i];
            convertToUpperCase(topics[i]);
        }
        std::sort(topics.begin(), topics.end(), TopicsComparator());
        std::vector <std::pair<std::string, std::string>> prohibitied(p);
        std::set <std::pair<std::string, std::string>> duplicates;
        for(int i = 0 ; i < p ; ++i){
            std::string a,b; 
            std::cin >> a >> b;
            convertToUpperCase(a);
            convertToUpperCase(b);
            if(isSwapNeeded(a,b)) std::swap(a,b);
            if(duplicates.find({a,b}) == duplicates.end()){
                duplicates.insert({a,b});
                std::tie(prohibitied[i].first, prohibitied[i].second) = std::tie(a,b);
            }
        }
        std::cout << "Set " << ++k << ":\n";
        backtrack(topics, prohibitied, s);
        std::cout << '\n';
    }
    return 0;
}
