#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <unordered_set>

bool isMagicSquarePossible(const std::string &str){
    double sqrtLength = std::sqrt(str.length());
    return std::floor(sqrtLength) == std::ceil(sqrtLength);
}

bool isMagicSquare(const std::vector<std::vector<char>> &table){
    std::unordered_set <std::string> us;

    std::string horizontal_forward;
    for(int i = 0 ; i < table.size() ; ++i){
        for(int j = 0 ; j < table[i].size() ; ++j){
            horizontal_forward += table[i][j];
        }
    }
    us.insert(horizontal_forward);

    std::string horizontal_backward;
    for(int i = table.size() - 1 ; i >= 0 ; --i){
        for(int j = table[i].size() - 1 ; j >= 0 ; --j){
            horizontal_backward += table[i][j];
        }
    }
    us.insert(horizontal_backward);

    std::string vertical_forward;
    for(int i = 0 ; i < table.size() ; ++i){
        for(int j = 0 ; j < table.size() ; ++j){
            vertical_forward += table[j][i];
        }
    }
    us.insert(vertical_forward);

    std::string vertical_backward;
    for(int i = table.size() - 1 ; i >= 0 ; --i){
        for(int j = table.size() - 1 ; j >= 0 ; --j){
            vertical_backward += table[j][i];
        }
    }
    us.insert(vertical_backward);

    return us.size() == 1;
}

int calculateDimension(const std::string &sentence){
    int dimension = std::sqrt(sentence.length());
    std::vector<std::vector<char>> table(dimension, std::vector<char>(dimension));
    auto it = sentence.begin();
    for(int i = 0 ; i < dimension ; ++i){
        for(int j = 0 ; j < dimension ; ++j){
            table[i][j] = *it++;
        }
    }
    return isMagicSquare(table) ? dimension : -1;
}

int main(int argc, char const *argv[])
{
    int T, k = 0;
    std::cin >> T;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(T--){
        std::string input;
        std::getline(std::cin, input);
        std::string sentence;
        for(int i = 0 ; i < input.length() ; ++i){
            if(input[i] >= 'a' && input[i] <= 'z') sentence += input[i];
        }
        std::cout << "Case #" << ++k << ":\n";
        if(!isMagicSquarePossible(sentence)){
            std::cout << "No magic :(\n";
            continue;
        }
        int dimension = calculateDimension(sentence);
        if(dimension == -1){
            std::cout << "No magic :(\n";
        } else{
            std::cout << dimension << '\n';
        }
    }
    return 0;
}
