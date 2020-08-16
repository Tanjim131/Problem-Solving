#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector <vector<int>> square(3, vector<int>(3));
    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            cin >> square[i][j];
        }
    }
    int a = square[0][1] + square[0][2];
    int b = square[1][0] + square[1][2];
    int c = square[2][0] + square[2][1];
    int d = square[0][2] + square[2][0];
    // x + z = d
    // x + a = z + c
    // z = (d + a - c) / 2
    int z = (d + a - c) / 2;
    int x = d - z;
    // x + a = y + b
    int y = x + a - b;
    
    square[0][0] = x;
    square[1][1] = y;
    square[2][2] = z;
    
    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            cout << square[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
