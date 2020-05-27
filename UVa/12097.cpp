#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

constexpr double PI = 3.1415926535897932384626433832795;
constexpr double EPS = 0.0001;

bool check(const std::vector <double> &volumes, double val, int num_friends){
    int counter = 0;
    for(int i = 0 ; i < volumes.size() ; ++i){
        counter += floor(volumes[i] / val);
        if(counter >= num_friends) return true;
    }
    return counter >= num_friends;
}

double bs(const std::vector <double> &volumes, double sum, int num_friends){
    double lo = 0, hi = sum;
    while(hi - lo > EPS){
        double mid = (lo + hi) / 2;
        if(check(volumes, mid, num_friends)) lo = mid;
        else hi = mid; 
    }
    return lo;
}

int main(int argc, char const *argv[])
{
    int T; std::cin >> T;
    while(T--){
        int n,f; std::cin >> n >> f;
        std::vector <int> radius(n);
        std::vector <double> compute(n);
        double sum = 0;
        for(int i = 0 ; i < n ; ++i){
            std::cin >> radius[i];
            compute[i] = radius[i] * radius[i];
            sum += compute[i];
        }
        std::cout << std::fixed << bs(compute, sum, f + 1) * PI << '\n';
    }
    return 0;
}
