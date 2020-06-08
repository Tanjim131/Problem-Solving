#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <limits>

inline bool isValid(std::vector<int> &row_values, int row_value, int column_value){
    for(int previous_column = 0 ; previous_column < column_value ; ++previous_column){
        if(row_values[previous_column] == row_value) return false;
        if(std::abs(row_value - row_values[previous_column]) == std::abs(column_value - previous_column)) return false;
    }
    return true;
}

void backtrack(std::vector<int> &row_values, std::vector<std::vector<int>> &valid_rows_values, int column = 0){
    if(column == row_values.size()){
        // valid solution
        valid_rows_values.emplace_back(row_values);
        return;
    }
    for(int row = 0 ; row < row_values.size() ; ++row){
        if(isValid(row_values, row, column)){
            row_values[column] = row;
            backtrack(row_values, valid_rows_values, column + 1);
        }
    }
}

int answer(const std::vector<std::vector<int>> &valid_rows_values, const std::vector<int> &invalid_row_values){
    int minimum = std::numeric_limits<int>::max();
    for(int i = 0 ; i < valid_rows_values.size() ; ++i){
        int difference = 0;
        for(int j = 0 ; j < valid_rows_values[i].size() ; ++j){
            if(valid_rows_values[i][j] + 1 != invalid_row_values[j]) ++difference;
        }
        minimum = std::min(minimum, difference);
    }
    return minimum;
}

int main(int argc, char const *argv[])
{
    std::vector <std::vector<int>> valid_rows_values;
    std::vector<int> row_values(8,0);
    backtrack(row_values, valid_rows_values);
    int k = 0;
    std::string input;
    while(std::getline(std::cin, input)){
        std::vector <int> invalid_row_values(8);
        std::istringstream iss(input);
        int token;
        for(int i = 0 ; iss >> token ; ++i){
            invalid_row_values[i] = token;
        }
        std::cout << "Case " << ++k << ": " << answer(valid_rows_values, invalid_row_values) << '\n';
    }
    return 0;
}
