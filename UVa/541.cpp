#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>

std::tuple <bool, int, int> check(std::vector<std::vector<int>> &matrix){
    int row = -1, col = -1;
    for(int i = 0 , counter = 0 ; i < matrix.size() ; ++i){
        int rowSum = std::accumulate(matrix[i].begin(), matrix[i].end(), 0);
        if(rowSum & 1){
            row = i;
            ++counter;
        }
        if(counter == 2) return std::make_tuple(false, -1, -1);
    }

    int col_num = matrix[0].size();
    for(int i = 0 , counter = 0; i < col_num ; ++i){
        int colSum = 0;
        for(int j = 0 ; j < matrix.size() ; ++j) colSum += matrix[j][i];
        if(colSum & 1){
            col = i;
            ++counter;
        }
        if(counter == 2) return std::make_tuple(false, -1, -1);
    }

    if(row == -1 && col == -1) return std::make_tuple(true, row, col); // row and col both ok

    int r = -1, c = -1;
    
    //std::cout << "row " << row << " col " << col << '\n';

    if(row == -1){
        // row is ok, col is not ok
        for(int i = 0 ; i < matrix.size() ; ++i){
            // toggle each row bit
            matrix[i][col] ^= 1;
            // check if column is ok
            int rowSum = 0;
            for(int j = 0 ; j < col_num ; ++j) rowSum += matrix[i][j];
            if(!(rowSum & 1)){
                r = row;
                c = i;
                break;
            }
            matrix[i][col] ^= 1; // did not work, restore
        }
    } else if(col == -1){
        // col is ok, row is not ok
        for(int i = 0 ; i < col_num ; ++i){
            // toggle each row bit
            matrix[row][i] ^= 1;
            // check if column is ok
            int colSum = 0;
            for(int j = 0 ; j < matrix.size() ; ++j) colSum += matrix[j][i];
            if(!(colSum & 1)){
                r = row;
                c = i;
                break;
            }
            matrix[row][i] ^= 1; // did not work, restore
        }
    } else{
        // bot row and col are not ok
        matrix[row][col] ^= 1;
        // check if both are now ok
        int rowSum = 0;
        for(int i = 0 ; i < col_num ; ++i) rowSum += matrix[row][i];
        if(!(rowSum & 1)){
            int colSum = 0;
            for(int i = 0 ; i < matrix.size() ; ++i) colSum += matrix[i][col];
            if(!(colSum & 1)){
                r = row;
                c = col;
            }
        }
    }

    if(r == -1 && c == -1) return std::make_tuple(false, r, c);
    return std::make_tuple(true, r, c);
}

int main(int argc, char const *argv[])
{
    int n;
    while(std::cin >> n && n != 0){
        std::vector <std::vector<int>> matrix(n, std::vector <int>(n));
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                std::cin >> matrix[i][j];
            }
        } 
        
        auto ret = check(matrix);
        if(std::get<0>(ret) && std::get<1>(ret) == -1 && std::get<2>(ret) == -1 ) std::cout << "OK\n";
        else if(!std::get<0>(ret) && std::get<1>(ret) == -1 && std::get<2>(ret) == -1){
            std::cout << "Corrupt\n";
        } else{
            std::cout << "Change bit (" << std::get<1>(ret) + 1 << "," << std::get<2>(ret) + 1 << ")\n";
        }
    }
    return 0;
}
