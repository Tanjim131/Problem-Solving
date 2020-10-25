#include <iostream>
#include <limits>

using namespace std;

int compute_min_packages(int n, int k){
    int min_packages = numeric_limits<int>::max();
    for(int i = 1 ; i * i <= n ; ++i){
        if(n % i == 0){
            int p = i, q = n / i;
            if(q <= k){
                min_packages = min(min_packages, p);
            }
            if(p <= k){
                min_packages = min(min_packages, q);
            } 
        }
    }
    return min_packages;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << compute_min_packages(n, k) << '\n';
    }
    return 0;
}
