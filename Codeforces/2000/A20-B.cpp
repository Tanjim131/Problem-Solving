#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char const *argv[])
{
    long long A,B,C;
    std::cin >> A >> B >> C;
    if(!A && !B){
        if(!C) std::cout << "-1\n";
        else std::cout << "0\n";
        return 0;
    }
    // a quadratic equation has at most two distinct roots
    long long discriminant  = B * B - 4 * A * C;
    if(discriminant < 0){
        std::cout << "0\n";
    } else if(!discriminant){
        // equal roots
        double root = -B / (2.0 * A);
        std::cout << "1\n";
        std::cout << std::fixed << std::setprecision(17) << root << '\n';
    } else{
        // discriminant > 0
        // if A != 0, then two distinct roots
        // if A == 0, then one root
        if(!A){
            double root = - C * 1.0 / B;
            std::cout << "1\n";
            std::cout << std::fixed << std::setprecision(17) << root << '\n';
        } else{
            std::cout << "2\n";
            double sqrtDiscrimintant = std::sqrt(discriminant);
            double root1 = (-B - sqrtDiscrimintant) / (2.0 * A);
            double root2 = (-B + sqrtDiscrimintant) / (2.0 * A);
            if(root1 < root2){
                std::cout << std::fixed << std::setprecision(17) << root1 << '\n' << root2 << '\n';
            } else{
                std::cout << std::fixed << std::setprecision(17) << root2 << '\n' << root1 << '\n';
            }
        }
    }
    return 0;
}
