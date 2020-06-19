#include <iostream>
#include <cmath>

int check(int n, double p, int check_value){
    int exponentCheck, exponentTarget;
    double mantissaCheck = frexp(check_value, &exponentCheck);
    double mantissaTarget = frexp(p, &exponentTarget);

    double mantissaCheckRaisedToPowerN = std::pow(mantissaCheck, n);
    double multiplier = 0.5 / mantissaCheckRaisedToPowerN;
    int powerToSubtract = static_cast<int>(std::ceil(std::log2(multiplier)));
    int exponentProduct = exponentCheck * n - powerToSubtract;

    if(exponentProduct < exponentTarget) return -1;
    if(exponentProduct > exponentTarget) return 1;

    double mantissaProduct = mantissaCheckRaisedToPowerN * std::pow(2, powerToSubtract);
    double difference = std::abs(mantissaProduct - mantissaTarget);

    constexpr double EPS = 1e-10; // works between 1e-10 and 1e-15
    if(difference < EPS) return 0;
    if(mantissaProduct < mantissaTarget) return -1;
    return 1;
}

int binarySearch(int n, double p){
    int low = 1, high = 1e9;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        int status = check(n, p, mid);
        if(!status){
            ans = mid;
            break;
        } else if(status == -1){
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    double p;
    while(std::cin >> n >> p){
        // double rhs = std::log(p) / n;
        // double k = std::exp(rhs);
        // std::cout << static_cast<int>(std::nearbyint(k)) << '\n';
        std::cout << binarySearch(n,p) << '\n';
    }
    return 0;
}
