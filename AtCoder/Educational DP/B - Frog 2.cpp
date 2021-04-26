#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int solve(const vector <int> &heights, vector <int> &dp, int K, int current){
    if(current == 0){
        return 0;
    }
    if(dp[current] != -1){
        return dp[current];
    }
    int min_cost = numeric_limits<int>::max();
    for(int i = 1 ; i <= K ; ++i){
        int cost_i = numeric_limits<int>::max();
        if(current - i >= 0){
            cost_i = solve(heights, dp, K, current - i) + abs(heights[current] - heights[current - i]);
        }
        min_cost = min(min_cost, cost_i);
    }
    return dp[current] = min_cost;
}

int main(int argc, char const *argv[])
{
    int N, K;
    cin >> N >> K;
    vector <int> heights(N);
    for(int i = 0 ; i < N ; ++i){
        cin >> heights[i];
    }
    vector <int> dp(N, -1);
    cout << solve(heights, dp, K, N - 1) << '\n';
    return 0;
}
