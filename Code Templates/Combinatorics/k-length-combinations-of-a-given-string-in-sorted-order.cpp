#include <iostream>

void generate_combination(const std::string &sequence, int k, int start_from = 0, std::string combination = ""){
    if(combination.length() == k) {
        std::cout << combination << '\n';
        return;
    }
    for(int i = start_from ; i < sequence.length() ; ++i){
        if(i != start_from && sequence[i] == sequence[i - 1]) continue;
        generate_combination(sequence, k, i + 1, combination + sequence[i]);
    }
}

int main(int argc, char const *argv[])
{
    std::string sequence = "aabbc";
    int k = 3;
    generate_combination(sequence, k);
    return 0;
}
