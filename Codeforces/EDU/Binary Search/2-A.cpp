#include <iostream>
#include <cmath>

using namespace std;


bool ok(int w, int h, int n, long long value){
    long long ww = value / w;
    long long hh = value / h;
    return value >= w && value >= h && ww >= n * 1.0 / hh;
}

constexpr int iterations = 100;

long long binary_search(int w, int h, int n){
    long long low = 0, high = 1e18;
    for(int i = 0 ; i < iterations ; ++i){
        long long mid = (low + high) / 2;
        if(ok(w, h, n, mid)){
            high = mid;
        } else{
            low = mid;
        }
    }
    return high;
}

int main(int argc, char const *argv[])
{
    int w, h, n;
    cin >> w >> h >> n;
    cout << binary_search(w, h, n) << '\n';
    return 0;
}
