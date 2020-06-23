#include <iostream>
#include <iomanip>
#include <cmath>

// 0 <= p, r <= 20
// -20 <= q, s, t <= 0
int compute_status(double val, int p, int q, int r, int s, int t, int u){

    // if val increases then "a" decreases and "b" increases
    // if val decreases then "a" increases and "b" decreases

    double a = p * std::exp(-val) + r * std::cos(val); // >= 0
    double b = q * std::sin(val) + s * std::tan(val) + t * val * val; // <= 0
    
    if(u < 0) b += u;
    else a += u;

    b *= -1.0; // make b positive to compare absolute values

    double difference = std::abs(a - b);
    constexpr double EPS = 1e-7;
    if(difference < EPS) return 0;
    if(a < b) return -1; // need to increase a and decrease b, i.e need to decrease "val"
    return 1; // need to decrease a and increase b, i.e need to increase "val"
}

double binary(int p, int q, int r, int s, int t, int u){
    double low = 0.0 , high = 1.0;
    double ans = -1.0;
    constexpr double EPS = 1e-9; // 1e-9 or lower
    while(high - low > EPS){
        double mid = (low + high) / 2.0;
        int status = compute_status(mid, p, q, r, s, t, u);
        if(!status){
            ans = mid;
            break;
        }
        else if(status == -1){
            high = mid;
        } else{
            low = mid;
        }
    }
    return ans;
}

int main(){
    int p, q, r, s, t, u;
    while(std::cin >> p >> q >> r >> s >> t >> u){
        double answer = binary(p, q, r, s, t, u);
        if(answer == -1.0){
            std::cout << "No solution\n";
        } else {
            std::cout << std::fixed << std::setprecision(4) << answer << '\n';
        }
    }

    return 0;
}