#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = acos(-1.0);

// n = 3, r = 100 results in highest outer circle radius
// n * acos(term) = 360
// acos(term) = 120
// term = -1/2
// R^2 - 6 * r * R - 3 * r^2 = 0
// R = 646.410

bool ok(int n, int r, double R){
    double term = ((r + R) * (r + R) - 2 * R * R) / (r + R) / (r + R);
    double angle = n * acos(term) * 180.0 / PI; // radian to degrees
    return angle <= 360.0;
}

double binary_search(int n, int r){
    double low = 0.0, high = 650.0; 
    for(int i = 0 ; i < 100 ; ++i){
        double mid = (low + high) / 2;
        if(ok(n, r, mid)){
            low = mid;
        } else{
            high = mid;
        }
    }
    return low;
}

int main(int argc, char const *argv[])
{
    int n, r;
    cin >> n >> r;
    cout << fixed << setprecision(17) << binary_search(n, r) << '\n';
    return 0;
}
