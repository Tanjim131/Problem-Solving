#include <iostream>
#include <vector>

using std::cin;
using std::cout;

bool isCenterSymmetric(const std::vector <std::vector<char>> &terminal){
    int dimension = terminal.size();
    int middle = dimension * dimension / 2;
    bool symmetric = true;
    for(int i = 0 ; i != middle ; ++i){
        int r = i / 3;
        int c = i % 3;
        if(terminal[r][c] != terminal[dimension - 1 - r][dimension - 1 - c]){
            symmetric = false;
            break;
        }
    }
    return symmetric;
}

int main(int argc, char const *argv[])
{
    std::vector <std::vector <char>> terminal(3, std::vector <char>(3));
    for(int i = 0 ; i < terminal.size() ; ++i){
        for(int j = 0 ; j < terminal[i].size() ; ++j){
            cin >> terminal[i][j];
        }
    }
    if(isCenterSymmetric(terminal)){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
    return 0;
}
