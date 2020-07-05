#include <iostream>
#include <vector>

std::vector <std::string> generate_permutation(const std::string &input, int index){
    if(!index){
        return std::vector <std::string> {std::string(1, input[index])};
    }
    
    std::vector <std::string> ret = generate_permutation(input, index - 1);

    std::vector <std::string> permutations;
    permutations.reserve(3628800); // 9! x 10 = 3628800, max input length = 10, size of ret = 9! and index = 10 in the worst case

    for(const std::string &p : ret){
        for(int i = 0 ; i <= index ; ++i){
            std::string permutation = p.substr(0, i) + input[index] + p.substr(i);
            permutations.emplace_back(permutation);
        }
    }

    return permutations;
}

void printPermutations(const std::vector <std::string> &permutations){
    for(int i = 0 ; i < permutations.size() ; ++i){
        std::cout << permutations[i] << '\n';
    }
}

int main(int argc, char const *argv[])
{
    std::string input;
    int k = 0;
    while(std::cin >> input){
        std::vector <std::string> permutations = generate_permutation(input, input.length() - 1);
        if(k > 0) std::cout << '\n';
        printPermutations(permutations);
        ++k;
    }
    return 0;
}
