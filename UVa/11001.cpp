#include <iostream>
#include <cstdlib>
#include <cmath>

inline bool isNearlyEqual(double a, double b, double EPSILON = 1e-6)
{
    return std::abs(a - b) < EPSILON;
}

int solve(int V_total, int V_0){
    div_t result = std::div(V_total, 2 * V_0);
    int maxN = result.quot;
    if(result.rem){
        int f = result.quot; // floor value
        int c = f + 1; // ceil value

        double f_len = 0.0;
        if(f) f_len = 0.3 * f * std::sqrt(V_total * 1.0 / f - V_0); // f can be 0
        double c_len = 0.3 * c * std::sqrt(V_total * 1.0 / c - V_0);

        if(isNearlyEqual(f_len, c_len)) maxN = 0; 
        else if(f_len < c_len) maxN = c;
        else maxN = f;
    } 
    return maxN;
}

int main(int argc, char const *argv[])
{
    int V_total,V_0;
    while(std::cin >> V_total >> V_0){
        if(!V_total && !V_0) break;
        std::cout << solve(V_total, V_0) << '\n';
    }
    return 0;
}