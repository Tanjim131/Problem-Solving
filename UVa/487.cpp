#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

std::vector<std::vector<int>> direction = {
    {1,0},
    {-1, 0},
    {0, 1},
    {0,-1},
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1,-1}
};

struct SetComparator{
    bool operator()(const std::string &left, const std::string &right){
        if(left.length() == right.length()) return left < right;
        return left.length() < right.length();
    }
};

bool isValidPosition(int new_x, int new_y, const std::vector <std::vector<char>> &table){ // table - n x n
    return new_x >= 0 && new_x < table.size() && new_y >= 0 && new_y < table.size(); 
}

void backtrack(const std::vector <std::vector<char>> &table, std::vector <std::vector<char>> &visited, std::set<std::string,SetComparator> &answers, std::string current_word, int x, int y){
    if(current_word.length() > 2){
        if(answers.find(current_word) == answers.end()) {
            answers.insert(current_word);
        }
    }
    visited[x][y] = '1';
    for(int i = 0 ; i < direction.size() ; ++i){
        int new_x = x + direction[i][0];
        int new_y = y + direction[i][1];
        if(isValidPosition(new_x, new_y, table) && visited[new_x][new_y] == '0'){
            char cp = table[x][y];
            char np = table[new_x][new_y];
            if(np > cp){ // increasing ascii
                backtrack(table, visited, answers, current_word + np, new_x, new_y);
            }
        }
    }
    visited[x][y] = '0'; // backtrack
}

void printAnswers(const std::set <std::string,SetComparator> &answers){
    for(const auto &answer : answers){
        std::cout << answer << '\n';
    }
}

int main(int argc, char const *argv[])
{
    int T,k = 0;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        std::vector <std::vector<char>> table(n, std::vector<char>(n));
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                std::cin >> table[i][j];
            }
        }
        std::set <std::string, SetComparator> answers;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                std::vector <std::vector<char>> visited(n, std::vector<char>(n, '0'));
                backtrack(table, visited, answers, std::string(1, table[i][j]), i, j);
            }
        }
        if(k > 0) std::cout << '\n';
        printAnswers(answers);
        ++k;
    }
    return 0;
}
