#include <iostream>
#include <vector>
 
using namespace std;
 
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        // O(26 * N) solution
        vector <vector<int>> range_freq(n + 1, vector<int>(26, 0));
        vector <int> count(26, 0);
        for(int i = 1 ; i <= n ; ++i){
            ++range_freq[i][s[i - 1] - 'a'];
            ++count[s[i - 1] - 'a'];
            for(int j = 0 ; j < 26 ; ++j){
                range_freq[i][j] += range_freq[i - 1][j];
            }
        }
        vector <int> p(m);
        for(int i = 0 ; i < m ; ++i) {
            cin >> p[i];
            for(int j = 0 ; j < 26 ; ++j){
                count[j] += range_freq[p[i]][j];
            }
        }
        for(int i = 0 ; i < 26 ; ++i){
            cout << count[i] << " \n"[i + 1 == 26];
        }
    }
    return 0;
}