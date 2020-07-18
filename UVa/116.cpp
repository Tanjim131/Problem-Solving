#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

const std::vector <std::pair<int,int>> direction{
    {-1, 1},
    {0, 1},
    {1, 1}
};

// dp[i][j] -> minimal weight path starting at (i,j)
// cr - current_row, cc - current_column

int call(const std::vector <std::vector<int>> &matrix, std::vector <std::vector<int>> &dp, std::vector <std::vector<int>> &parent, int cr, int cc = 0){
    if(cc == matrix[cr].size() - 1){
        return dp[cr][cc] = matrix[cr][cc];
    }
    if(dp[cr][cc] != std::numeric_limits<int>::max()){
        return dp[cr][cc];
    }
    int minimum = std::numeric_limits<int>::max();
    for(int i = 0 ; i < direction.size() ; ++i){
        int nr = (cr + direction[i].first + matrix.size()) % matrix.size(); // matrix.size() is unsigned (size_t)
        int nc = cc + direction[i].second;
        int ret = matrix[cr][cc] + call(matrix, dp, parent, nr, nc);
        if(ret < minimum){
            minimum = ret;
            parent[cr][cc] = nr;
        } else if(ret == minimum && nr < parent[cr][cc]){
            parent[cr][cc] = nr;
        }
    }
    return dp[cr][cc] = minimum;
}

void printPath (const std::vector <std::vector<int>> &parent, int row, int col = 0){
    while(true){
        if(parent[row][col] == -1){
            std::cout << row + 1 << '\n';
            break;
        }
        std::cout << row + 1 << " ";
        row = parent[row][col];
        ++col;
    }
}

int main(int argc, char const *argv[])
{
    int m,n;
    while(std::cin >> m >> n){
        std::vector <std::vector<int>> matrix(m, std::vector <int>(n)), parent(m, std::vector<int>(n, -1)), dp(m, std::vector<int>(n, std::numeric_limits<int>::max()));
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                std::cin >> matrix[i][j];
            }
        }
        std::vector <int> path; 
        path.reserve(n);
        int min_sum = std::numeric_limits<int>::max();
        int min_row = -1;
        for(int i = 0 ; i < m ; ++i){    
            int ret = call(matrix, dp, parent, i);
            if(ret < min_sum){
                min_sum = ret;
                min_row = i;
            }
        }
        printPath(parent, min_row);        
        std::cout << min_sum << '\n';
    }
    return 0;
}
