#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int solve(const vector <int> &heights, vector <int> &dp, int current){
    if(current == 0){
        return 0;
    }
    if(dp[current] != -1){
        return dp[current];
    }
    int cost1 = solve(heights, dp, current - 1) + abs(heights[current] - heights[current - 1]);
    int cost2 = numeric_limits <int>::max();
    if(current > 1) cost2 = solve(heights, dp, current - 2) + abs(heights[current] - heights[current - 2]);
    return dp[current] = min(cost1, cost2);
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector <int> heights(N);
    for(int i = 0 ; i < N ; ++i){
        cin >> heights[i];
    }
    vector <int> dp(N, -1);
    cout << solve(heights, dp, N - 1) << '\n';
    return 0;
}
