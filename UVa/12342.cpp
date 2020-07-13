#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Tax{
    public:
        int range;
        double percentage;

        Tax(){}
        Tax(int _r, double _p) : range(_r), percentage(_p){}
};

int calculate_tax(int k, const std::vector <Tax> &taxes){
    double tax = 0.0;
    for(int i = 0 ; i < taxes.size() ; ++i){
        if(k >= taxes[i].range){
            tax += taxes[i].range * taxes[i].percentage;
        } else{
            tax += k * taxes[i].percentage;
        }
        k -= taxes[i].range;
        if(k <= 0)  break;
    }
    if(k > 0) tax += k * 0.25;
    return static_cast<int>(std::ceil(tax));
}

int main(int argc, char const *argv[])
{
    std::vector <Tax> taxes{
        {180000, 0.00}, 
        {300000, 0.10}, 
        {400000, 0.15},
        {300000, 0.20},
    };
    int T, i = 0;
    std::cin >> T;
    while(T--){
        int k;
        std::cin >> k;
        int answer = 0;
        if(k > 180000) answer = std::max(calculate_tax(k, taxes), 2000);
        std::cout << "Case " << ++i << ": " << answer << '\n';
    }
    return 0;
}
