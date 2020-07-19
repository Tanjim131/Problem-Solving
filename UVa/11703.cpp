#include <iostream>
#include <vector>
#include <cmath>

int compute(int i, std::vector <int> &dp, int mod = 1000000){
    if(!i) return 1;
    if(dp[i] != -1) return dp[i];
    int a = static_cast<int>(i - std::sqrt(i));
    int b = static_cast<int>(std::log(i));
    double sine = std::sin(i);
    int c = static_cast<int>(i * sine * sine);
    return dp[i] = (compute(a,dp) + compute(b,dp) + compute(c,dp)) % mod;
}

int main(int argc, char const *argv[])
{
    std::vector <int> dp(1000000 + 5, -1);
    int i;
    while(std::cin >> i){
        if(i == -1) break;
        std::cout << compute(i, dp) << '\n';
    }
    return 0;
}
