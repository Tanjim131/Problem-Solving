#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool ok(const vector <int> &ropes, int k, double value){
    int counter = 0;
    for(auto rope : ropes){
        counter += rope / value;
    }
    return counter >= k;
}

double binary_search(const vector <int> &ropes, int k){
    double low = 0.0, high = 1e11;
    for(int i = 0 ; i < 100 ; ++i){
        double mid = (low + high) / 2;
        if(ok(ropes, k, mid)){
            low = mid;
        } else{
            high = mid;
        }
    }
    return high;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector <int> ropes(n);
    for(int i = 0 ; i < n ; ++i) cin >> ropes[i];
    cout << fixed << setprecision(17) << binary_search(ropes, k) << '\n';
    return 0;
}
