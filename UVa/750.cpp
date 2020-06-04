#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

bool canBePlaced(const std::vector<int> &column_vector, int row_candidate, int current_column){
    // as we're going from column = 0 to column = 7
    // check the previous columns
    for(int previous_column = 0 ; previous_column < current_column ; ++previous_column){
        if(column_vector[previous_column] == row_candidate) return false; 
        if(std::abs(current_column - previous_column) == std::abs(row_candidate - column_vector[previous_column])) return false;
    }
    return true;
}

void printSolution(const std::vector <int> &column_vector, int counter){
    std::cout << std::setw(2) << counter << "      "; // 6 spaces
    for(int i = 0 ; i < column_vector.size() ; ++i){
        std::cout << column_vector[i] + 1;
        if(i != column_vector.size() - 1) std::cout << " ";
    }
    std::cout << '\n';
}

void backtrack(std::vector <int> &column_vector, int &counter, int a, int b, int column = 0){
    if(column == column_vector.size()){
        // valid solution
        printSolution(column_vector, ++counter);
        return;
    }
    for(int row = 0 ; row < column_vector.size() ; ++row){
        // check the constraint
        if(column == b && row != a) continue;
        if(canBePlaced(column_vector, row, column)){
            column_vector[column] = row;
            backtrack(column_vector, counter, a, b, column + 1);
        }
    }
}

void prePrint(){
    std::cout << "SOLN       COLUMN\n"; // 7 spaces
    std::cout << " #      "; // 6 spaces 
    for(int i = 1 ; i <= 8 ; ++i){
        std::cout << i;
        if(i != 8) std::cout << " ";
    }
    std::cout << "\n\n";
}

int main(int argc, char const *argv[])
{
    int T, k = 0;
    std::cin >> T;
    while(T--){
        int a,b;
        std::cin >> a >> b;
        if(k > 0) std::cout << '\n';
        prePrint();
        std::vector <int> column_vector(8, 0);
        int counter = 0;
        backtrack(column_vector, counter, --a, --b);
        ++k;
    }
    return 0;
}
