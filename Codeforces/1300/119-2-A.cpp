#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int solve(int rem, vector <int> &dp, int a, int b, int c){
    if(rem < 0) return numeric_limits<int>::min();
    if(rem == 0) return 0;
    if(dp[rem] != -1) return dp[rem];
    int ret = max({solve(rem - a, dp, a, b, c), solve(rem - b, dp, a, b, c), solve(rem - c, dp, a, b, c)}) + 1;
    return dp[rem] = ret;
}

int main(int argc, char const *argv[])
{
    // O(n) solution
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector <int> dp(n + 1, -1);
    cout << solve(n, dp, a, b, c) << '\n';
    // O(n^2) solution
    // int maximum = 0;
    // int p = n / a;
    // for(int i = 0 ; i <= p ; ++i){
    //     int rem_sum = n - i * a;
    //     int q = rem_sum / b;
    //     for(int j = 0 ; j <= q ; ++j){
    //         int rs = rem_sum - j * b;
    //         if(rs % c == 0){
    //             maximum = max(maximum, i + j + rs / c);
    //         }
    //     }
    // }
    // cout << maximum << '\n';
    return 0;
}
