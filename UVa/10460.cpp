#include <iostream>
#include <vector>
#include <cmath>

constexpr double EPS = 0.1;

std::vector <int> compute_indices(const std::string &input, int target_position){
    std::vector <int> positions; 
    positions.reserve(input.length());

    long long product = 1;
    
    int i = input.length() - 1;
    for(; i > 0 ; --i){
        double division = target_position * 1.0 / product;
        if(division < EPS) break;
        int position = (static_cast<int>(std::ceil(division)) - 1) % (i + 1);
        positions.emplace_back(position);
        product *= (i + 1);
    }

    while(i > 0){
        positions.emplace_back(0);
        --i;
    }

    return positions;
}

std::string printPermutation(const std::string &input, int target_position){
    std::vector <int> positions = compute_indices(input, target_position);
    std::string permutation = std::string(1, input[0]);
    for(int i = positions.size() - 1 ; i >= 0 ; --i){
        permutation.insert(permutation.begin() + positions[i], input[positions.size() - i]);
    }
    return permutation;
}

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        std::string input;
        int position;
        std::cin >> input >> position;
        std::cout << printPermutation(input, position) << '\n';
    }
    return 0;
}
