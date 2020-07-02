#include <iostream>
#include <limits>
#include <vector>

class Cell{
    public:
        int x,y;
        Cell(){}
        Cell(int _x, int _y) : x(_x), y(_y){}
};

// 0-based indexing
int determineSubBoardIndex(const Cell &cell){
    if(cell.x <= 1 && cell.y <= 1) return 0;
    if(cell.x <= 1 && cell.y > 1) return 1;
    if(cell.x > 1 && cell.y <= 1) return 2;
    return 3;
}

bool isValidPlacement(const std::vector<std::vector<char>> &sudoku_board, const Cell &cell, char value){
    // check the row
    int row = cell.x;
    for(int i = 0 ; i < sudoku_board[row].size() ; ++i){
        if(sudoku_board[row][i] == '*') continue;
        if(sudoku_board[row][i] == value) return false;
    }
    // check the column
    int column = cell.y;
    for(int i = 0 ; i < sudoku_board.size() ; ++i){
        if(sudoku_board[i][column] == '*') continue;
        if(sudoku_board[i][column] == value) return false;
    }
    // check the 2x2 sub-board
    int subboard = determineSubBoardIndex(cell);
    std::div_t result = std::div(subboard, 2);
    int subboardStartX = subboard - result.rem;
    int subboardStartY = result.rem * 2;
    for(int i = 0 ; i < 2 ; ++i){
        for(int j = 0 ; j < 2 ; ++j){
            int posX = subboardStartX + i;
            int posY = subboardStartY + j;
            if(sudoku_board[posX][posY] == '*') continue;
            if(sudoku_board[posX][posY] == value) return false;
        }
    }
    return true;
}

void printBoard(const std::vector<std::vector<char>> &sudoku_board){
    for(int i = 0 ; i < sudoku_board.size() ; ++i){
        for(int j = 0 ; j < sudoku_board[i].size() ; ++j){
            std::cout << sudoku_board[i][j];
        }
        std::cout << '\n';
    }
}

void backtrack(std::vector<std::vector<char>> &sudoku_board, const std::vector<Cell> &empty_cells, int index = 0){
    if(index == empty_cells.size()){
        printBoard(sudoku_board);
        return;
    }
    for(int i = 1 ; i <= 4 ; ++i){
        char value = i + '0';
        if(isValidPlacement(sudoku_board, empty_cells[index], value)){
            int x = empty_cells[index].x;
            int y = empty_cells[index].y;
            sudoku_board[x][y] = value;
            backtrack(sudoku_board, empty_cells, index + 1);
            sudoku_board[x][y] = '*'; // backtrack
        }
    }
}

int main(int argc, char const *argv[])
{
    int T, k = 0;
    std::cin >> T;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(T--){
        if(k > 0) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::vector<std::vector<char>> sudoku_board(4, std::vector<char>(4));
        std::vector <Cell> empty_cells; empty_cells.reserve(16);
        for(int i = 0 ; i < 4 ; ++i){
            for(int j = 0 ; j < 4 ; ++j){
                std::cin >> sudoku_board[i][j];
                if(sudoku_board[i][j] == '*') {
                    empty_cells.emplace_back(Cell(i, j));
                }
            }
        }
        std::cout << "Case #" << ++k << ":\n";
        backtrack(sudoku_board, empty_cells);
    }
    return 0;
}
