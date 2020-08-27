#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


bool compute_status(double C, double val){
    double term = val * val + sqrt(val);
    return term >= C;
}

constexpr int iterations = 100;

double binary_search(double C){
    double low = 0.0, high = 1e10;
    for(int i = 0 ; i < iterations ; ++i){
        double mid = (low + high) / 2;
        bool status = compute_status(C, mid);
        if(status){
            high = mid;
        } else{
            low = mid;
        }
    }
    return high;
}

int main(int argc, char const *argv[])
{
    double C;
    cin >> C;
    cout << fixed << setprecision(17) << binary_search(C) << '\n';
    return 0;
}
