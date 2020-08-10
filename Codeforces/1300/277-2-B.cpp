#include <iostream>
#include <vector>

using namespace std;

bool isValid(const vector <vector<char>> &matrix_b, const vector <vector<char>> &matrix_a){
    for(int i = 0 ; i < matrix_a.size() ; ++i){
        for(int j = 0 ; j < matrix_a[i].size() ; ++j){
            int OR = 0;
            for(int k = 0 ; k < matrix_a[i].size() ; ++k){
                    OR = OR || matrix_a[i][k] - '0';
            }
            for(int k = 0 ; k < matrix_b.size() ; ++k){
                OR = OR || matrix_a[k][j] - '0';
            }
            if(OR != matrix_b[i][j] - '0') return false;
        }
    }
    return true;
}

void print_matrix(const vector <vector<char>> &matrix){
    for(int i = 0 ; i < matrix.size() ; ++i){
        for(int j = 0 ; j < matrix[i].size() ; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}

vector <vector<char>> construct_matrix(const vector <vector<char>> &matrix_b){
    vector <vector<char>> matrix_a(matrix_b.size(), vector<char>(matrix_b[0].size(), '1'));
    for(int i = 0 ; i < matrix_b.size() ; ++i){
        for(int j = 0 ; j < matrix_b[i].size() ; ++j){
            if(matrix_b[i][j] == '0'){
                for(int k = 0 ; k < matrix_b[i].size() ; ++k){
                    matrix_a[i][k] = '0';
                }
                for(int k = 0 ; k < matrix_b.size() ; ++k){
                    matrix_a[k][j] = '0';
                }
            }
        }
    }
    return matrix_a;
}

int main(int argc, char const *argv[])
{
    int m,n;
    cin >> m >> n;
    vector <vector<char>> matrix_b(m, vector <char>(n));
    for(int i = 0 ; i < m ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin >> matrix_b[i][j];
        }
    }
    vector <vector<char>> matrix_a = construct_matrix(matrix_b);
    if(!isValid(matrix_b, matrix_a)){
        cout << "NO\n";
    } else{
        cout << "YES\n";
        print_matrix(matrix_a);
    }
    return 0;
}
