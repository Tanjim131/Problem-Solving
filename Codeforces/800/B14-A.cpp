#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;

void draw(const std::vector <std::vector <char>> &sheet){
    int firstRow = -1;
    int lastRow = std::numeric_limits <int>::min();
    int leftMost = sheet[0].size();
    int rightMost = 0;
    for(int i = 0 ; i < sheet.size() ; ++i){
        for(int j = 0 ; j < sheet[i].size() ; ++j){
            if(sheet[i][j] == '*'){
                if(firstRow == -1){
                    firstRow = i;
                }
                lastRow = std::max(lastRow, i);
                leftMost = std::min(leftMost, j);
                rightMost = std::max(rightMost, j);
            }
        }
    }
    for(int i = firstRow ; i <= lastRow ; ++i){
        for(int j = leftMost ; j <= rightMost ; ++j){
            cout << sheet[i][j];
        }
        cout << '\n';
    }
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    std::vector <std::vector <char>> sheet(n, std::vector <char>(m));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            cin >> sheet[i][j];
        }
    }
    draw(sheet);
    return 0;
}
