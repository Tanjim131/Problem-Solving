#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <vector<char>> v(n, vector<char>(n));
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                cin >> v[i][j];
            }
        }
        bool possible = true;
        for(int i = 0 ; i < n && possible ; ++i){
            for(int j = 0 ; j < n && possible ; ++j){
                if(v[i][j] == '1'){
                    if(i == n - 1 || j == n - 1) continue;
                    if(v[i + 1][j] != '1' && v[i][j + 1] != '1'){
                        possible = false;
                        break;
                    }
                }
            }
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
