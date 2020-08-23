#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int solve(int n, const vector <int> &qb, vector <int> &dp, vector <int> &denom){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n]; // dp[n] = minimum number of coins to make n out of quasi binary denominations
    int answer = numeric_limits<int>::max();
    for(int i = qb.size() - 1 ; i >= 0 ; --i){ // iteration from i = 0 to i < qb.size() such that qb[i] <= n will give the same answer
                                            // but it will compute a lot of sub-optimal answers at first
        if(qb[i] > n) continue; 
        int res = 1 + solve(n - qb[i], qb, dp, denom); // take this denomination
        if(answer > res){ // if by taking the denomination qb[i], we get a better answer, then update the answer
            answer = res;
            denom[n] = qb[i]; // record for which denomination we got a better answer for n
        }
    }
    return dp[n] = answer;
}

int main(int argc, char const *argv[])
{
    vector <int> qb; 
    qb.reserve(100);
    for(int i = 1 ; ; ++i){
        bitset <32> b(i);
        int value = stoi(b.to_string()); // convert binary representation to string and take its integer value
        if(value > 1e6) break;
        qb.emplace_back(value);
    }
    int n; 
    cin >> n;
    vector <int> dp(n + 1, -1), denom(n + 1, -1);
    cout << solve(n, qb, dp, denom) << '\n';
    while(denom[n] != -1){ // print the solution
        cout << denom[n] << " ";
        n -= denom[n];
    }
    return 0;
}
