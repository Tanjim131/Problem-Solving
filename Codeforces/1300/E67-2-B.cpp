#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

// int compute_status(const vector <vector <int>> &cumulative_freq, const vector <int> &freq, int value){
//     for(int i = 0 ; i < 26 ; ++i){
//         if(cumulative_freq[value][i] < freq[i]){
//             return -1;
//         }
//     }
//     return 1;
// }

// int binary_search(const vector <vector <int>> &cumulative_freq, const vector <int> &freq){
//     int low = 0, high = cumulative_freq.size() - 1;
//     int ans = 0;
//     while(low <= high){
//         int mid = (low + high) / 2;
//         int status = compute_status(cumulative_freq, freq, mid);
//         if(status == 1){
//             ans = mid;
//             high = mid - 1;
//         } else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    //vector <vector <int>> cumulative_freq(n, vector <int>(26, 0));
    vector <vector <int>> positions(26);
    for(int i = 0 ; i < s.length() ; ++i){
        // if(i != 0){
        //     for(int j = 0 ; j < 26 ; ++j){
        //         cumulative_freq[i][j] = cumulative_freq[i - 1][j];
        //     }   
        // }
        // ++cumulative_freq[i][s[i] - 'a'];
        positions[s[i] - 'a'].emplace_back(i + 1);
    }
    int m;
    cin >> m;
    for(int i = 0 ; i < m ; ++i){
        string t;
        cin >> t;
        vector <int> freq(26, 0);
        for(int j = 0 ; j < t.length() ; ++j) ++freq[t[j] - 'a'];
        //int ans = binary_search(cumulative_freq, freq);
        //cout << ans + 1 << '\n';
        int ans = -1;
        for(int j = 0 ; j < 26 ; ++j){
            // assert(freq[j] - 1 < positions[j].size());
            if(freq[j] > 0) ans = max(ans, positions[j][freq[j] - 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}
