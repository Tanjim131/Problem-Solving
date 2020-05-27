#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

class Segment{
    public:
        int distance, speed;
};

class Pair{
    public:
        bool decrease, increase;
};

constexpr double EPS = 1e-7;

Pair check(double c, double t, const std::vector <Segment> &segments){
    double calculated_time = 0.0;
    for(int i = 0 ; i < segments.size() ; ++i){
        double value = segments[i].speed + c;
        if(value < EPS) return {false, true}; // need to increase c
        calculated_time += segments[i].distance / (segments[i].speed + c);
    }
    if(calculated_time < t) return {true, false}; // need to decrease c
    return {false, true}; // need to increase c
}

double binary_search(double t, const std::vector <Segment> &segments){
    double lo = -1000 + EPS, hi = 1e6 + 1000.00;
    while(hi - lo > EPS){
        double mid = (lo + hi) / 2;
        Pair ret = check(mid, t, segments);
        if(ret.decrease){
            hi = mid;
        } else{
            lo = mid;
        }
    }
    return lo;
}

int main(int argc, char const *argv[])
{
    int n, t;
    while(std::cin >> n >> t){
        std::vector <Segment> segments(n);
        for(int i = 0 ; i < n ; ++i){
            std::cin >> segments[i].distance >> segments[i].speed;
        }
        std::cout << std::setprecision(10) << binary_search(t, segments) << '\n';
    }
    return 0;
}
