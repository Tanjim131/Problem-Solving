#include <iostream>
#include <cmath>
#include <iomanip>

constexpr double pi = 3.1415926535897932384626;

int main(){
    int l,w,h,theta;
    while(std::cin >> l >> w >> h >> theta){
        double threshold = std::atan(h * 1.0 / l);
        double angle = theta * pi / 180.0;
        double remaining_milk_volume;
        if(angle > threshold){
            remaining_milk_volume = 0.5 * std::tan(pi / 2.0 - angle) * h * h * w;
        } else{
            double empty_area = 0.5 * l * std::tan(angle) * l * w;
            remaining_milk_volume = l * w * h - empty_area;
        }
        std::cout << std::fixed << std::setprecision(3) << remaining_milk_volume << " mL\n";
    }
    return 0;
}
