#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

int computeStatus(double value, int C_0, const std::vector<int> &cashFlows){\
    double sum = 0.0;
    for(int i = 0 ; i < cashFlows.size() ; ++i){
        sum += cashFlows[i] / std::pow(1 + value, i + 1);
    }
    double difference = std::abs(sum - C_0);
    constexpr double EPS = 1e-7;
    if(difference < EPS) return 0;
    if(sum < C_0) return -1; // need a lower IRR
    return 1; // need a higher IRR
}

double binarySearch(int C_0, const std::vector <int> &cashFlows){
    double low = -1, high = 1e4;
    double ans = -1.0;
    constexpr double EPS = 1e-12;
    while(high - low > EPS){
        double mid = (low + high) / 2;
        int status = computeStatus(mid, C_0, cashFlows);
        if(!status){
            ans = mid;
            break;
        } else if(status == -1){
            high = mid; // lower IRR needed
        } else{
            low = mid; // higher IRR needed
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int T;
    while(std::cin >> T && T){
        int C_0;
        std::cin >> C_0;
        std::vector <int> cashFlows(T);
        for(int i = 0 ; i < T ; ++i){
            std::cin >> cashFlows[i];
        }
        std::cout << std::fixed << std::setprecision(2) << binarySearch(-C_0, cashFlows) << '\n';
    }
    return 0;
}
