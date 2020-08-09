#include <iostream>
#include <vector>

using namespace std;

// bool isValidPosition(int i, int j, int n, int m){
//     return i >= 0 && i < n && j >= 0 && j < m;
// }

// int check(vector < vector <char> > &belt, int i, int j, int n, int m){
//     int prev_i = -1, prev_j = -1;
//     while(isValidPosition(i, j, n, m) && belt[i][j] != 'C'){
//         prev_i = i;
//         prev_j = j;
//         if(belt[i][j] == 'R'){
//             ++j;
//         } else{    
//             ++i;
//         }
//     }
//     if(!isValidPosition(i, j, n, m)){
//         if(belt[prev_i][prev_j] == 'R'){
//             belt[prev_i][prev_j] = 'D';
//         } else{
//             belt[prev_i][prev_j] = 'R';
//         }
//         return 1;
//     }
//     return 0;
// }

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector < vector<char> > belt(n, vector<char> (m));
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                cin >> belt[i][j];
            }
        }
        int counter = 0;
        // for(int i = 0 ; i < n ; ++i){
        //     for(int j = 0 ; j < m ; ++j){
        //         counter += check(belt, i, j, n, m);
        //     }
        // }
        for(int i = 0 ; i < n - 1 ; ++i){
            if(belt[i][m - 1] == 'R') ++counter;
        }
        for(int j = 0 ; j < m - 1 ; ++j){
            if(belt[n - 1][j] == 'D') ++counter;
        }
        cout << counter << '\n';
    }
    return 0;
}
