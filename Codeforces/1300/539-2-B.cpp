#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> compute_factors(int n){
    vector <int> factors; factors.reserve(n);
    for(int i = 2 ; i * i <= n ; ++i){
        if(n % i == 0){
            factors.emplace_back(i);
        }
    }
    return factors;
}

// Wrong assumptions:
//      1. Only the divisors of the largest number will minimize total power
//      2. The biggest divisor <= sqrt(max(powers)) will minimize total power

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> powers(n);
    int total_power = 0;
    for(int i = 0 ; i < n ; ++i){
        cin >> powers[i];
        total_power += powers[i];
    }
    sort(powers.begin(), powers.end());
    int min_total_power = total_power;
    for(int i = n - 1 ; i > 0 ; --i){
        vector <int> factors = compute_factors(powers[i]);
        for(int j = 0 ; j < factors.size() ; ++j){
            int new_power = total_power - (powers[i] - powers[i] / factors[j]) + (powers[0] * factors[j] - powers[0]);
            min_total_power = min(min_total_power, new_power);
        }
    }
    cout << min_total_power << '\n';
    return 0;
}
