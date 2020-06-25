#include <iostream>
#include <vector>
#include <algorithm>

void generate_combination(const std::string &sequence, int k, std::string combination = "", int start_from = 0){
    if(combination.length() == k){
        std::cout << combination << '\n';
        return;
    }
    for(int i = start_from ; i < sequence.size() ; ++i){
        if(i != start_from && sequence[i] == sequence[i - 1]) continue;
        generate_combination(sequence, k, combination + sequence[i], i + 1);
    }
}

int main(int argc, char const *argv[])
{
    std::string s;
    int r;
    while(std::cin >> s >> r){
        std::sort(s.begin(), s.end()); // sorting the string doesn't change the combinations but guarantees lexicographical order
        generate_combination(s, r);
    }
    return 0;
}
