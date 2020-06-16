#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

inline bool isValidPosition(std::vector<int> &queen_column_values, const std::vector <std::vector<int>> &chess_board, int current_row, int chosen_column){
    // check all previous rows for column conflict and diagonal conflict
    for(int previous_row = 0 ; previous_row < current_row ; ++previous_row){
        if(queen_column_values[previous_row] == chosen_column) return false;
        if(current_row - previous_row == std::abs(chosen_column - queen_column_values[previous_row])) return false;
    }
    return true;
}

int backtrack(std::vector<int> &queen_column_values, const std::vector <std::vector<int>> &chess_board, int current_row = 0, int sum = 0){
    if(current_row == chess_board.size()){
        // reached the end, a valid solution has been found
        return sum;
    }
    // check all column for current row
    int ans = -1;
    for(int chosen_column = 0 ; chosen_column < 8 ; ++chosen_column){
        if(isValidPosition(queen_column_values, chess_board, current_row, chosen_column)){
            // choose "chosen_column" as the column value for "current_row"
            queen_column_values[current_row] = chosen_column;
            int ret = backtrack(queen_column_values, chess_board, current_row + 1, sum + chess_board[current_row][chosen_column]);
            ans = std::max(ans, ret);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int k;
    std::cin >> k;
    while(k--){
        std::vector <std::vector<int>> chess_board(8, std::vector<int>(8)); // chess boards are 8x8 in dimension
        for(int i = 0 ; i < 8 ; ++i){
            for(int j = 0 ; j < 8 ; ++j){
                std::cin >> chess_board[i][j];
            }
        }
        // 8 queens will be placed in 8 rows, each row containing exactly one queen
        // we'll figure out the column of each row where the queen for that row will be placed
        std::vector <int> queen_column_values(8,0); // initially column values for all rows are 0
        // we'll use recursive backtracking to place the 8 queens such that the maximum score is attained
        int ans = backtrack(queen_column_values, chess_board);
        std::cout << std::setw(5) << std::right << ans << '\n';
    }
    return 0;
}
