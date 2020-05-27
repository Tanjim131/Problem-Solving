// Example program
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
 
constexpr int MAX_HOUSES = 20;
 
int dp[MAX_HOUSES + 5][3];
 
inline int mod(int a, int b){
    int ret = a % b;
    if(ret < 0) ret += b;
    return ret;
}
 
int solve(const std::vector <std::vector<int>> &costs, int cur_house, int cur_pos){
    if(cur_house == costs.size() - 1) return dp[cur_house][cur_pos] = costs[cur_house][cur_pos];
    if(dp[cur_house][cur_pos] != -1) return dp[cur_house][cur_pos];
    int cost = costs[cur_house][cur_pos] + std::min(solve(costs, cur_house + 1, mod(cur_pos - 1, 3)), solve(costs, cur_house + 1, mod(cur_pos + 1, 3)));
    return dp[cur_house][cur_pos] = cost;
}
 
int main()
{
    int T, k = 0; std::cin >> T;
    while(T--){
        int house_num; std::cin >> house_num;
        std::vector <std::vector<int>> costs(house_num, std::vector<int> (3));
        for(int i = 0 ; i < house_num ; ++i){
            std::vector <int> cost(3);
            for(int j = 0 ; j < 3 ; ++j) std::cin >> cost[j];
            costs[i] = cost;
        }
        memset(dp, -1, sizeof(dp));
        int answer = std::numeric_limits<int>::max();
        for(int i = 0 ; i < 3 ; ++i){  
            answer = std::min(answer, solve(costs, 0, i));
        }
        std::cout << "Case " << ++k << ": " << answer << '\n';
    }
    return 0;
}