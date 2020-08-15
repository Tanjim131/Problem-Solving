#include <iostream>
#include <vector>

using namespace std;

// long long count_subsequence(const string &s, const string &t, vector<vector<long long>> &dp, int s_i = 0, int t_i = 0){
//     if(t_i == t.length()) return 1;
//     if(s_i == s.length()) return 0;
//     if(dp[s_i][t_i] != -1) return dp[s_i][t_i];
//     if(s[s_i] == 'v'){
//         if(s_i < s.length() - 1 && s[s_i + 1] == 'v' && t[t_i] == 'v'){
//             return dp[s_i][t_i] = count_subsequence(s, t, dp, s_i + 2, t_i + 2) + count_subsequence(s, t, dp, s_i + 1, t_i);
//         } 
//     } else if(s[s_i] == t[t_i]){
//         return dp[s_i][t_i] = count_subsequence(s, t, dp, s_i + 1, t_i + 1) + count_subsequence(s, t, dp, s_i + 1, t_i);
//     } 
//     return dp[s_i][t_i] = count_subsequence(s, t, dp, s_i + 1, t_i);
// }

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    string s;
    cin >> s;
    //string t = "vvovv"; // wow
    // vector <vector<long long>> dp(s.length(), vector <long long>(t.length(), -1));
    // cout << count_subsequence(s, t, dp) << '\n';
    long long vv = 0, vvo = 0, vvovv = 0;
    for(int i = 0 ; i < s.length() ; ++i){
        if(s[i] == 'o'){
            vvo += vv;
        } else if(i > 0 && s[i - 1] == 'v'){
            ++vv;
            vvovv += vvo; 
        }
    }
    cout << vvovv << '\n';
    return 0;
}
